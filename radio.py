from flask import Flask
from flask import render_template
from flask import request
from predefines import host, port, txtFile, templateFile
from predefines import isInteger
import subprocess

app = Flask(__name__)

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
			cmd=['mpc', 'play']
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
			out,err = p.communicate()
		elif request.form['submit'] == 'turn radio off':
			cmd=['mpc', 'stop']
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
			out,err = p.communicate()	
		elif request.form['submit'] == 'change':
			cmd=['mpc', 'play', str(request.form['station'])]
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
			out,err = p.communicate()
		elif request.form['submit'] == '+5':
			cmd=['mpc', 'volume', '+5']
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
		elif request.form['submit'] == '-5':
			cmd=['mpc', 'volume', '-5']
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
		elif request.form['submit'] == 'update playlist':
			cmd=['mpc', 'clear']
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)	
			for stationURL in stationURLs:
				cmd=['mpc', 'add', stationURL]
				p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
		
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
		
	cmd=['mpc', 'current']
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
	status = p.stdout.read()
	cmd=['mpc', 'volume']
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
	volume = p.stdout.read()	
	
	return render_template(templateFile, name=name, stations=stationOutput.strip(), status=status, volume=volume)
	
if __name__ == '__main__':
	app.run(host=host, port=port, debug=True)
	

