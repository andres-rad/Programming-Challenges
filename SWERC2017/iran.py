from PIL import Image


dicc = {}

c = 'a'
s = ''

for x in range(576):
	img = "poke_{}.png".format(x)
	img = Image.open(img)

	p_val = list(im.getdata())

	if p_val not in dicc:
		dicc[p_val] = c
		c = chr(ord(c)+1)

	s += c




