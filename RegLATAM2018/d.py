n = int(input())

prov = {"" : {}}
for x in range(n):
	s = input()
	# print(s)
	name, provider = s.split('@')
	# print(name)
	# print(provider)
	name = name.split('+')[0].replace('.', '') 
	# print(name)
	if provider not in prov:
		prov[provider] = {}
		# prov.update({provider : {}})
	prov[provider][name] = 1
# print(prov)
ans = 0
for _, e in prov.items():
	ans += len(e)
print (ans)