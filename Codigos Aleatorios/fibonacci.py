dicio = {}

def fibonacci(n):

	if n == 1 or n == 0:
		return 1

	try:
		if dicio[n] != 0:
			return dicio[n]
	except Exception:
		dicio[n] = fibonacci(n-2) + fibonacci(n-1)

	return dicio[n]

while True:

	try:
		print('Numero de fibonacci: ' + str(fibonacci(int(input("")))))
	except EOFError:
		break

print("Fim")