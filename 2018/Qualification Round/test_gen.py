from random import randint

t = 100
n = 10**5

f = open("test.txt", 'w')
f.write(str(t) + "\n")

for i in range(0, t):
    f.write(str(n) + '\n')

    for i in range(0, n):
	    f.write(str(randint(0, 10**9)) + ' ')
    f.write('\n')

f.close()
