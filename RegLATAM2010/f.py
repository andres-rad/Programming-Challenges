sentence = input()
while sentence != "*":
	letra = 0
	tautograma = True
	palabras = sentence.split()
	for palabra in palabras:
		palabra = palabra.lower()
		if letra == 0:
			letra = palabra[0]
		elif palabra[0] != letra:
			tautograma = False
			break
	if tautograma:
		print("Y")
	else:
		print("N")
	sentence = input()