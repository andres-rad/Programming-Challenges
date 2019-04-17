t = int(input())
r = 0
c = 0
vis = []

def dfs(x, y, tot):
	if tot == r*c:
		print ("POSSIBLE")
		print (x+1, y+1)
		return True
	vis[x][y] = 1
	for i in range(r):
		for j in range(c):
			if not vis[i][j]:
				a = i != x
				a &= j != y
				a &= (i-j) != (x-y)
				a &= (i+j) != (x+y)
				if a:
					if dfs(i, j, tot+1):
						print(x+1, y+1)
						return True
	vis[x][y] = 0
	return False

for x in range(t):
	print("Case #{}: ".format(x+1), end='')

	r, c = map(int, input().split())

	vis = []
	for x in range(r):
		vis.append([])
		for y in range(c):
			vis[x].append(0)



	if not dfs(0, 0, 1):
		print ("IMPOSSIBLE")