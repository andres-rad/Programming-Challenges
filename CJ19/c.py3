from math import gcd

t = int(input())
caso = 1
while t > 0:
    t -= 1
    n, l = list(map(int, input().split()))
    # print((n, l))
    ls = []
    ls = list(map(int, input().split()))
    # print("ls: {}".format(ls))
    primos = {}
    for x in range(l):
        for y in range(l):
            # y = x+1
            if ls[x] != ls[y]:
                
                primo = gcd(ls[x], ls[y])
                # print(type(primo))
                if primo != 1:
                    primos[primo] = True
                # else:
                    # print(l[x], l[y])
                    # x = 1/0
    otros = {k:True for k in primos.keys()}
    for p in primos:
        for ll in ls:
            if ll%p == 0 and ll//p != 1:
                otros[ll//p] = True
        # print(p)
    # print(len(otros))
    beg = 'A'
    primos = {}
    for p in sorted(list(otros)):
        primos[p] = beg
        beg = chr(1 + ord(beg))
    # print(primos)

    divisoresPrim = []
    # x = 1/0
    if ord(beg) > ord('Z')+1:
        x = 1/0
    while len(primos) != 26:
        x = 1/0
    for p, _ in primos.items():
        if ls[0] % p == 0:
            divisoresPrim.append(p)
    while len(divisoresPrim) > 2:
        x = 1/0
    while len(divisoresPrim) == 0:
        x = 1/0
    ans = []
    for d in divisoresPrim:
        nextP = d

        for li in ls:
            # print("next: {} ".format(nextP))
            ans.append(nextP)
            if li % nextP != 0:
                # print("fallo")
                ans = []
                break
            nextP = li//nextP
        if ans:
            ans.append(nextP)
            break

    # print(l)    
    while len(ans) != l+1:
        x = 1/0
    # print("".join(map(lambda p : primos[p]  ,ans)))
                
    
    print("Case #{}: {}".format(caso, "".join(map(lambda p : primos[p]  ,ans))))
    caso += 1