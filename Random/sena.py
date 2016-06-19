from random import randint

N = []

while True:
	n = randint(0,60)
	if ( n in N ):
		continue
	else:
		N.append(n)

	if len(N) == 6:
		break

N.sort()

print(N)