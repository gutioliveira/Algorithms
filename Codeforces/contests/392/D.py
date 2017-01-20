b = 0
value = 0

v = ""

b = int(input(""))

v = input("")

vetor = []

aux = ""

while len(v) > 0:

	n = v[-1] + aux

	if int(n) >= b:

		vetor.append(aux)

		if ( aux[0] == '0' and len(aux) > 1 ):
			i = 0

			while i < len(aux) - 1:
				if aux[i] == '0':
					v += aux[i]
				else:
					break

				i += 1

		aux = ""
	else:
		aux = v[-1] + aux
		v = v[:-1]

vetor.append(aux)

soma = 0

i = 0

for I in vetor:

	soma += int(I) * b ** i

	i += 1

print(soma) 
