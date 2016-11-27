#!/usr/bin/python
# -*- coding: utf-8 -*-

from crontab import CronTab
import datetime
from flask import Flask
from flask import render_template
from flask import request
from flask_apscheduler import APScheduler
from predefines import host, port, txtFile, templateFile
from predefines import isInteger, mpcCommand
import subprocess
import smbus
import time

i2c_bus = smbus.SMBus(1)
i2c_address = 0x04

class Config(object):
    JOBS = [
        {
            'id': 'job1',
            'func': '__main__:job1',
            'args': (1, 2),
            'trigger': 'interval',
            'seconds': 10
        }
    ]
    SCHEDULER_VIEWS_ENABLED = True

	
def job1(a, b):
    print(str(a) + ' ' + str(b))
	

app = Flask(__name__)
app.config.from_object(Config())

scheduler = APScheduler()
scheduler.init_app(app)

@app.route('/', methods=['GET', 'POST'])	
def hello_world(name='Flask FM'):
	stations = []
	stationURLs = []
	stationOutput = ''
	
	for x in open(txtFile,'r'):
		a = x.split("|")		
		stations.append(a[0])	
		stationURLs.append(a[1].strip())
		
	if request.method == 'POST':
		if request.form['submit'] == 'turn radio on':
			mpcCommand(['mpc', 'play'])
		elif request.form['submit'] == 'turn radio off':
			i2c_write(3)
			#mpcCommand(['mpc', 'stop'])
		elif request.form['submit'] == 'change':
			mpcCommand(['mpc', 'play', str(request.form['station'])])
		elif request.form['submit'] == '+5':
			mpcCommand(['mpc', 'volume', '+5'])
		elif request.form['submit'] == '-5':
			mpcCommand(['mpc', 'volume', '-5'])
		elif request.form['submit'] == 'update playlist':
			mpcCommand(['mpc', 'clear'])
			for stationURL in stationURLs:
				mpcCommand(['mpc', 'add', stationURL])
		elif request.form['submit'] == 'update alarms':
			cron = CronTab(user='myself')			
			cron.remove_all(comment='radio alarm ON') #make a nice function	
			cron.remove_all(comment='radio alarm OFF')			

			onValue = str(request.form['turnOn'])
			if len(onValue) == 5 :					
				inputs = onValue.split(':')
				job = cron.new(command='mpc play', comment='radio alarm ON')
				job.hour.on(inputs[0])
				job.minute.on(inputs[1])			
					
				print "new ON at " + inputs[0] + ":" + inputs[1]
			offValue = str(request.form['turnOff'])
			if len(offValue) == 5 :				
				inputs = offValue.split(':')
				job = cron.new(command='mpc stop', comment='radio alarm OFF')
				job.hour.on(inputs[0])
				job.minute.on(inputs[1])								
				print "new OFF at " + inputs[0] + ":" + inputs[1]
			cron.write()
			
		
	position = mpcCommand(['mpc', '-f', '%position%'])
	idx = position.split('[')
	position = idx[0].strip()

	if isInteger(position) == False:
		position = 0

	x = 1
	for station in stations:
		stationOutput += '<option value="' + str(x) + '" '
		if x == int(position):
			stationOutput += 'selected="selected"'
		stationOutput += '>' + station + '</option>'
		x += 1	
		
	status = unicode(mpcCommand(['mpc', 'current']), "utf-8")
	volume = mpcCommand(['mpc', 'volume'])
	localtime = datetime.datetime.strftime(datetime.datetime.now(), '%Y-%m-%d %H:%M:%S')
	#scheduler.start()
		
	alarmON = ""
	alarmOFF = ""
	alarms = ""
		
	cron = CronTab(user='myself')
	for job in cron:
		splitter = str(job.render()).split(' ')
		if splitter[6] == "play":
			alarmON = str(splitter[1]).zfill(2) + ":" + str(splitter[0]).zfill(2)
		if splitter[6] == "stop":
			alarmOFF = str(splitter[1]).zfill(2) + ":" + str(splitter[0]).zfill(2)
		
		alarms += job.render() + '<br/>'
	
	print(alarmON)
	print(alarmOFF)
	
	return render_template(templateFile, name=name, stations=stationOutput.strip(), status=status, volume=volume, localtime=localtime, alarmON=alarmON, alarmOFF=alarmOFF, alarms=alarms)

def i2c_write(value):
	i2c_bus.write_byte(i2c_address, value)	
	
def i2c_read():
	value = i2c_bus.read_byte(i2c_address)
	return value
	
if __name__ == '__main__': 
	app.run(host=host, port=port, debug=True)
	

