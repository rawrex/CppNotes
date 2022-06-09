from random import choice

params = ['T', 'const T', 'T&', 'const T&', 'T*', 'const T*', 'T&&']

class Template:
	def __init__(self, t, param):
		self.t = t
		self.param = param 
	
	def testParam(self, arg):
		pass

	def testT(self, arg):
		pass

def makeTemplate(params=params):
	param = choice(params)
	print('\ntemplate <typename T>')
	print(f'void f({param} param);\n')

if __name__ == '__main__':
	makeTemplate()
	while input('>>> ') == '':
		makeTemplate()
