from random import shuffle

def isSorted(l):
	return l == sorted(l)

def newList(n = 40000):
	l = [i for i in range(n)]
	while(1):
		shuffle(l)
		yield l

def merge(l, r):
	return sorted(l + r)

def stepSort(l):
	ans = []
	right = []
	left = []
	next = 0
	while next < len(l):
		if not right:
			right = [l[next]]
		else:
			if right[-1] < l[next]:
				right.append(l[next])
			elif (not left) or left[-1] < l[next]:
				left.append(l[next])
			else:
				ans += merge(left, right)
				# print("left: {}, right: {}, merge: {}, ans: {}".format(left, right, merge(left, right), ans))
				left = []
				right = []
				next -= 1
		next += 1
	ans += merge(left, right)

	return ans

for l in newList(80):
	for x in range(5):
		l = stepSort(l)
	if (l != sorted(l)):
		print("l: {}".format(l))
		print("sorted: {}".format(sorted(l)))