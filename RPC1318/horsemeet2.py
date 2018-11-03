import numpy  as np

def m(i, j, k , l):
	return i + 8*j + 8*8*k + 8*8*8*l

def r(i, j):
	ans = []
	dx = [1, 1, 2, 2, -1, -1, -2, -2];
	dy = [2, -2, 1, -1, -2, 2, -1, 1];

	for d in range(8):
		if (i+dx[d] < 8 and
			i + dx[d] >= 0 and
			j + dy[d] < 8 and
			j + dy[d] >= 0):
			ans.append((i+dx[d], j+dy[d]))
	return ans

a = np.zeros((64*64, 64*64))
b = np.zeros(64*64)
eq = 0

# for i in range(8):
# 	for j in range(8):
# 		a[eq][m(i, j, i ,j)] = 1
# 		b[eq] = 0
# 		eq += 1

for i in range(8):
	for j in range(8):
		for k in range(8):
			for l in range(8):
				b[eq] = 1
				a[eq][m(i, j, k, l)] = 1
				R = r(i, j)
				for (u, v) in R:
					a[eq][m(k, l, u, v)] = 1.0 / len(R)
				eq+= 1

print(b)
print(eq)
print(r(0, 0))
x = np.linalg.solve(a, b)
# inp = input()
# print(inp)
i, j, k, l = map(int, input().split())
i-=1
j-=1
k-=1
l-=1
pbl = x[m(i, j, k, l)]
R = r(i, j)
pne = 0
for u, v in R:
	pne += x[m(k, l, u, v)]/len(R)
print(pbl)
print(pne)

for i in range(8):
	for j in range(8):
		for k in range(8):
			for l in range(8):
				pbl = x[m(i, j, k, l)]
				R = r(i, j)
				pne = 0
				for u, v in R:
					pne += x[m(k, l, u, v)]/len(R)
				# print("i: {}, j: {}, k: {}, l:{} ==> {} bl: {}, ne: {}".
					# format(i, j, k, l, pbl, pne, 'BL' if pbl > pne else 'NE'))
				if ((i + j + k + l) % 2 == 0 and pbl > pne):
					print('EROORR')
