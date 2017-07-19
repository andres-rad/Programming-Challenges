l = []
for n in range(1,64):
	for m in range(1,64):
		for k in range( (64 + n)/n + 1):
			cnd = 0
			a = (1<<n)-1
			for u in range(k):
				cnd += a
				a *= (1<<(m+n))
			if (cnd > 0):
				l += [cnd]
			cnd = 0
			a = (1<<n)-1
			a *= (1<<m)
			for u in range(k):
				cnd += a
				a *= (1<<(m+n))
			if (cnd > 0):
				l += [cnd]

l = sorted(list(set(l)))

def bina(x,l):
	if(x <= 0):
		return 0 
	lo = 0
	hi = len(l)
	while (hi - lo > 1):
		m = (hi + lo) / 2
		
		if(l[m] > x):
			hi = m
		else:
			lo = m
	
	return hi


x,y = map(int,raw_input().split())
ans = bina(y,l) - bina(x-1,l)
print (ans)
