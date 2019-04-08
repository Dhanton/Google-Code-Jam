from math import gcd

t = int(input())

for zz in range(t):
	n, l = [int(x) for x in input().split()]
	primes = list(range(l + 1))

	ct_numbers = list(range(l))
	first_index = 0
	lookfor = True

	i = 0
	for n in input().split():
		n = int(n)

		ct_numbers[i] = n

		if lookfor and i != 0 and ct_numbers[i] != ct_numbers[i - 1]:
			first_index = i
			lookfor = False

		i += 1

	primes[first_index] = gcd(ct_numbers[first_index - 1], ct_numbers[first_index])

	#Integer division (//) is needed to work with big numbers
	for i in range(first_index + 1, l + 1):
		primes[i] = ct_numbers[i - 1]//primes[i - 1]

	for i in range(first_index - 1, -1, -1):
		primes[i] = ct_numbers[i]//primes[i + 1]


	sorted_primes = sorted(set(primes))

	msg = str()
	for prime in primes:
		msg += chr(sorted_primes.index(prime) + ord('A'))

	print("Case #%d: %s" % (zz + 1, msg))