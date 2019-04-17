t = int(input())

from math import gcd

for x in range(t):
	print("Case #{}: ".format(x+1), end='')

	r, c = map(int, input().split())

	vuelta = r > c
	if vuelta:
		r, c = c, r
	ans = []

	for p in range(c*c + 10):
		if gcd(p, c) != 1:
			continue
		for salto in range(c):
			if (salto != 0) and (salto != r - 1) and (salto != c - r + 1):
				print("salto {}".format(salto))
				# el salto es valido, repartir 
				queda = p - salto - 2*(r-1)
				print("queda {}".format(queda))
				if queda < 0:
					break
				tmp = 2 + (queda  // (r-1))
				if queda % (r-1) == 0:
					if tmp < c - 1:
						print("Saltos de {} y ult de {}".format(tmp, salto))
				else:
					tmpG = queda % (r-1)
					if tmp + 1 < c - 1:
						print("Saltos Grandes de {} chicos de {} y ult de {}".format(tmp+1, tmp, salto))




	