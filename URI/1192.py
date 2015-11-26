teste = int(input(""))

for i in range(teste):
	string = input("")

	if (string[0] == string[2]):
		print(int(string[0])*int(string[2]))
	elif (ord(string[1]) >= 97 ):
		print(int(string[0]) + int(string[2]))
	else:
		print(int(string[2]) - int(string[0]))