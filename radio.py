from flask import Flask
from flask import render_template
from flask import request
from predefines import host, port, txtFile, templateFile
from predefines import isInteger, mpcCommand
from flask_apscheduler import APScheduler
import subprocess
import datetime

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
			mpcCommand(['mpc', 'stop'])
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
		
	cmd=['mpc', '-f', '%position%']
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
	position = p.stdout.read()
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
		
	status = mpcCommand(['mpc', 'current'])		
	volume = mpcCommand(['mpc', 'volume'])
	localtime = datetime.datetime.strftime(datetime.datetime.now(), '%Y-%m-%d %H:%M:%S')
	
	#scheduler.start()
	
	return render_template(templateFile, name=name, stations=stationOutput.strip(), status=status, volume=volume, localtime=localtime)

	
if __name__ == '__main__': 
	app.run(host=host, port=port, debug=True)
	

