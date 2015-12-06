i = 0
bissexto = False
ordinary = True

while True:

	try:
		s = int(input(""))
	except EOFError:
		break;

	if ( i != 0 ):
		print("")

	if ( s % 400 == 0 ):
		print("This is leap year.")
		bissexto = True
		ordinary = False
	elif ( s % 4 == 0 and s % 10 != 0 ):
		print("This is leap year.")
		bissexto = True
		ordinary = False
	if ( s % 15 == 0 ):
		print("This is huluculu festival year.")
		ordinary = False
	if ( s % 55 == 0 and bissexto ):
		print("This is bulukulu festival year.")
		ordinary = False

	if ( ordinary ):
		print("This is an ordinary year.")

	bissexto = False
	ordinary = True
	i = i + 1





