suits = ['D','H','C','S']
ranks = ['J','Q','K','A']

rC = {}
sC = {}
rScore = {}

for s in suits:
	sC[s] = 0
for r in ranks:
	rC[r] = 0
	rScore[r] = 10
for rn in range(2,11):
	r = str(rn)
	rC[r] = 0
	rScore[r] = rn

val = 0
changes = 0

minScore = 10
firstScore = -1

def processBuf(c):
	global val
	global minScore
	global firstScore
	global sC
	global rC
	global rScore

	#print(c)
	if c[0] == '1':
		r = '10'
		s = str(c[2])
	else:
		r = str(c[0])
		s = str(c[1])
	sC[s] += 1
	rC[r] += 1
	val += rScore[r]
	minScore = min(minScore, rScore[r])
	if firstScore == -1:
		firstScore = rScore[r]
	
buf = ""
for c in input():
	if c != ' ':
		buf += c
		continue
	processBuf(buf)
	buf = ''
processBuf(buf)

def debug(name,v):
	pass
	#print(name, v)
	#print()

debug("val",val)
debug("minScore",minScore)
debug("sC", sC)
debug("rC", rC)
debug("rScore", rScore)

#fns
def sumDivs(v):
	res = 0
	for i in range(1,v+1):
		if v % i == 0:
			res += i
	return res

#1
def p1():
	global val
	global changes
	global firstScore
	global rC
	val += 1
	val += firstScore * rC['J']
	changes += 1
	debug("1 val", val)
lastRule = p1

#2
def p2():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	anyS = False
	for s in suits:
		if sC[s] >= 2:
			anyS = True
	if anyS:
		val *= 2
		changes += 1
		debug("2 val", val)
		lastRule = p2

#3
def p3():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	allS = True
	for s in suits:
		if sC[s] == 0:
			allS = False
	if allS:
		val *= 2
		changes += 1
		debug("3 val", val)
		lastRule = p3

#4
def p4():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	black = sC['C'] + sC['S']
	red = sC['H'] + sC['D']
	if black != red:
		val += abs(black - red)
		changes += 1
		debug("4 val", val)
		lastRule = p4

#5
def p5():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if val % 2 == 0:
		val += sumDivs(val)
		changes += 1
		debug("5 val", val)
		lastRule = p5

#6
def p6():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if rC['7'] == 4:
		val -= 11*11 ## <<<<<<< Esto es 11 2 ???
		changes += 1
		debug("6 val", val)
		lastRule = p6

#7
def p7():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if val >= 0:
		val += minScore
		changes += 1
		debug("7 val", val)
		lastRule = p7

#8
def p8():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if val < 0:
		val *= -1
		changes += 1
		debug("8 val", val)
		lastRule = p8

#9
def p9():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if sC['D'] >= 3:
		val += 1
		changes += 1
		debug("9 val", val)

		tmp = rC['6']
		rC['6'] = rC['9']
		rC['9'] = tmp

		tmp = rC['2']
		rC['2'] = rC['5']
		rC['5'] = tmp
		debug("9 rC", rC)
		lastRule = p9

#10
def p10():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	straightCnt = 0
	straight = False
	for rn in range(2,11):
		r = str(rn)
		if rC[r] > 0:
			straightCnt += 1
		else:
			straightCnt = 0

		if straightCnt >= 5:
			straight = True
			break
	for r in ranks:
		if rC[r] > 0:
			straightCnt += 1
		else:
			straightCnt = 0

		if straightCnt >= 5:
			straight = True
			break
	if straight:
		val += rC['A'] * 5
		changes += 1
		debug("10 val", val)
		if rc['A'] != 0:
			lastRule = p10

#11
def p11():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if changes > 8:
		tmp = val
		if tmp != 0:
			lastRule = p11
		while tmp > 0:
			val += tmp % 2
			tmp //= 2
		changes += 1
		debug("11 val", val)
		# lastRule = p11

#12
def p12():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if rC['2'] >= 1:
		debug("12 val", val)
		lastRule()
		lastRule = p12

#13
def p13():
	global val
	global changes
	global firstScore
	global rC
	global sC
	global suits
	global lastRule
	if rC['2'] >= 1:
		val += abs(val)
		changes += 1
		debug("13 val", val)
		lastRule = p13

p1()
p2()
p3()
p4()
p5()
p6()
p7()
p8()
p9()
p10()
p11()
p12()
p13()

#14
print(val)
