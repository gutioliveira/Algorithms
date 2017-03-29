while True:

	x = input("")

	if x == "0":
		break

	print('Original number was %s' % x)

	d = {}

	d.update({x: 1})

	k = 0

	while True:

		x2 = ''.join(sorted(x))
		x1 = ''.join(sorted(x, reverse=True))

		x = str(((int(x1) - (int(x2)))))

		print('%d - %d = %s' % ((int(x1),int(x2),x)))

		k += 1

		if ( not x in d ):
			d.update({x: 1})
		else:
			print('Chain length %d\n' % k)
			break