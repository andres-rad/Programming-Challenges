n = int(input())

while(n != 0):
    l = []
    salidas = 0
    indet = 0
    for i in range(n):
        tarjeta, accion = input().split()
        h,m,s = map(int, tarjeta.split(":"))
        l.append((h,m,s,accion))
        if accion == 'X':
            salidas += 1
        elif accion == 'E':
            salidas -= 1
        else:
            indet += 1
    if salidas < 0:
        l = sorted(l, reverse=True)
        #print(l)
    else:
        l = sorted(l)

    cnt = 0
    res = 0
    reves = salidas < 0
    salidasR = abs(salidas)
    indet = (indet-salidasR)//2
    for (h, m, s, a) in l:
        #print (salidas)
        if a == 'X':
            cnt -=1
        elif a == 'E':
            cnt += 1
        elif a == '?':
            if salidas != 0:
                if salidas > 0:
                    salidas -= 1
                    cnt += 1
                else:
                    salidas += 1
                    cnt -= 1
            else:
                if indet > 0:
                    if reves:
                        cnt -= 1
                    else:
                        cnt += 1
                    indet -= 1
                else:
                    if reves:
                        cnt += 1
                    else:
                        cnt -= 1


        if reves:
            #print("cnt")
            #print (-cnt)
            res = max(res, -cnt)
        else:
            res = max(res, cnt)
    print(res )
    n = int(input())
