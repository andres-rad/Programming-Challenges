valores = { 'W':64, 'H':32, 'Q':16, 'E':8, 'S':4, 'T':2, 'X':1}

linea = input()

while linea != "*":
    correctos = 0
    parrafos = linea.split('/')
    for parrafo in parrafos:
        if len(parrafo) == 0:
            continue
        else:
            valor = sum(list(map(lambda x: valores[x], parrafo)))
            if valor == 64:
                correctos += 1
    print (correctos)
    linea = input()
