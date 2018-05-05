from random import randint

t = 100
n = 1000

f = open("test.txt", 'w')
f.write(str(t) + "\n")

for i in range(0, t):
    f.write(str(n) + '\n')

    for i in range(0, n):
	    f.write(str(randint(0, 1000)) + ' ')
    f.write('\n')

f.close()
