c, v = list(map(int, input().split()))

voters = []
cand = []
inv = []
for x in range(v):
	voters.append(input().split())
	inv.append({})
	for y in range(c):
		inv[x][voters[x][y]] = y
# print(inv)
trg = input()


orig_voters = [v[:] for v in voters]
for candi in voters[0]:
	cand.append(candi)
cand = sorted(cand)
# cand.remove(trg)
# orden = [trg]




orig_cand = cand

candpre = []
candpost = []
post = False
for candi in cand:
	if candi == trg:
		post = True
		continue
	if post:
		candpost.append(candi)
	else:
		candpre.append(candi)
# candpre, candpost = cand.split(trg)

# print(candpre)
# print(candpost)
candpost2 = []
maxs = trg

for post in candpost:
	count = 0
	for invi in inv:
		if (invi[post] < invi[trg]):
			count+=1
	if count*2 > v:
		candpre.append(post)
		maxs = max(maxs, post)
	else:
		candpost2.append(post)
candpost = candpost2
# print(candpre)
# print(candpost)
candpost = sorted(candpost)

post = False
candpost2 = []
for candi in candpost:
	if candi > maxs:
		candpost2.append(candi)
		# post = True
		# continue
		# if post:
	else:
		candpre.append(candi)
candpost = candpost2
candpre = sorted(candpre)
# print(candpre)
# print(candpost)

for cut in candpost:
	for x in range(len(voters)):
		if cut in voters[x]:
			voters[x] = voters[x][:voters[x].index(cut)]	
for x in range(len(voters)):
	if trg in voters[x]:
		voters[x] = voters[x][:voters[x].index(trg)]


# print(voters)
while [] in voters:
	voters.remove([])
# print(voters)

ans = []
candperdidos = candpre

while voters:
	cand = {}
	for voter in voters:
		for candi in voter:
			if candi not in cand:
				cand[candi] = 0
			cand[candi] += 1
	cand = {key : cand[key] for key in cand.keys() if cand[key]*2 <= v}
	# print(cand)
	if not cand:
		print('*')
		exit(0)

	maxs = '0'
	for candi in cand:
		maxs = max(maxs, candi)
	ans.append(maxs)
	candperdidos.remove(maxs)
	for x in range(len(voters)):
		if maxs in voters[x]:
			voters[x] = voters[x][:voters[x].index(maxs)]
	while [] in voters:
		voters.remove([])
candperdidos = sorted(candperdidos)
# print(candperdidos)
# destapados = 0
ans = list(reversed(ans)) 
ans += candpost
ansposta = []

#simulo
# candperdidos = []
# for cc in orig_cand:
	# if 
# print(candperdidos)
for x in range(c):
	# print(orig_voters[x])
	cnt = 0
	for vote in orig_voters:
		if vote[0] == trg:
			cnt += 1
	# print(cnt)
	# print(ans[0] if ans else -1)

	if candperdidos and ((not ans) or candperdidos[0] < ans[0]) and (trg == '$' or candperdidos[0] < trg):
		print('hola')
		ansposta.append( candperdidos[0])
		candperdidos = candperdidos[1:] 
	elif (not ans) or (cnt*2 > v and trg < ans[0]):
		ansposta.append(trg)
		# ansposta += ans
		trg = '$'
		# break
	else:
		ansposta.append(ans[0])
		# print(ans[0])
		for x in range(v):
			# print(orig_voters[x])
			# orig_voters[x] = (orig_voters[x]).remove(ans[0])
			orig_voters[x] = [k for k in orig_voters[x] if k != ans[0]]
			# print(orig_voters[x])
		# print(orig_voters)
		ans = ans[1:]




ans = ansposta #+ [trg] + ans
# v = 1//0
if(candperdidos):
	v = 1//0

# print(ans)
anss = ""
for elem in ans:
	anss += elem + ' '

print(anss)