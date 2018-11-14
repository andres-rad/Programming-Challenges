
def mcde(a, b):
	r = (0,0,0)
	if b == 0:
		# r[0] = a
		# r[1] = 1
		# r[2] = 0
		return (a, 1, 0)
	else:
		t = mcde(b, a%b)
		return (t[0], t[2], t[1] - a//b*t[2])

def modq(x, q):
	return (x % q + q) % q


def tcr(r, m):
	n = len(r)
	p = 0
	q = 1
	for i in range(n):
		p = modq(p-r[i], q)
		w = mcde(m[i], q)
		if p % w[0]:
			return -1
		q = q // w[0]*m[i]
		p = modq(r[i] + m[i] * p // w[0]*w[1], q)
	return p

b, z = list(map(int, input().split()))

init = []
to = []

for i in range(b):
	l = list(map(int, input().split()))
	init.append(l[0] -1 )
	to.append([])
	for j in range(z):
		to[i].append(l[j+1] - 1)

ans = 0
while ans < 200:
	curr = init[0]
	for i in init:
		curr = -1 if i != curr else curr
	if curr != -1:
		print("{} {}".format(curr+1, ans))
		exit(0)
	ans+=1
	for i in range(len(init)):
		init[i] = to[i][init[i]]

TCR = []

for i in range(b):
	TCR.append({})
	start = init[i]
	nxt = to[i][start]
	sz = 1
	while nxt != start:
		sz+=1
		nxt = to[i][nxt]
	# r = 0
	for x in range(sz):
		TCR[i][nxt] = (x, sz)
		nxt = to[i][nxt]


best = 10**23
bestz = -1
for zi in range(z):
	r = []
	m = []
	vale = True
	for i in range(b):
		if zi not in TCR[i]:
			vale = False
			break
		r.append(TCR[i][zi][0])
		m.append(TCR[i][zi][1])
	if vale:
		tmp = tcr(r, m)
		if tmp!=-1 and tmp < best:
			best = tmp
			bestz = zi

if bestz == -1:
	print('*')
else:
	print("{} {}".format(bestz+1, ans+best))
