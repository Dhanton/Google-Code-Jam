t = int(input())

for zz in range(t):
	n = input()

	num1 = str()
	num2 = str()

	for c in n:
		digit = int(c)

		if digit == 4:
			num1 += '3'
			num2 += '1'
		else:
			num1 += c
			num2 += '0'

	print("Case #%d: %s %s" % (zz + 1, num1, num2))