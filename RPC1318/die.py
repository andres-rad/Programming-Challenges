dies = [[[4]],
		[[0,8], [2,6]],
		[[0,4,8],[2,4,6]],
		[[0,2,6,8]],
		[[0,2,4,6,8]],
		[[0,1,2,6,7,8],[0,2,3,5,6,8]]
		]

die = []
for x in range(3):
	idx = 0
	for c in input():
		if c == 'o':
			die.append(3*x+idx)
		idx += 1

found = False
for idx, d in enumerate(dies):
	if die in d:
		print(idx + 1)
		found = True
		break

if not found:
	print('unknown')