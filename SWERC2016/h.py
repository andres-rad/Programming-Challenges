import sys

fact = [1 for n in range(35)]

for n in range(1,35):
	fact[n] = n * fact[n-1]

ans = set([])

def bt(i,l,s,f,d,h):
	global ans
	if i == (d - 1):
		c = h - 1 - s
		if c >= l:
			ne = fact[h-1] // (f * fact[c])
			#print(ne)
			ans.add(ne)
		return

	for j in range(l,h-s):
		bt(i+1,j,s+j,f*fact[j],d,h)


for line in sys.stdin:
	[d,h] = map(int,line.split())
	ans = set([])
	bt(0,0,0,1,d,h)
	l = sorted(list(ans))
	for x in l:
		print(x)
