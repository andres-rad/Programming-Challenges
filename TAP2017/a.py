d = ["DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#", "SI"]

(n,s) = input().split()

n = int(n)

m = [i for i in range(len(d)) if d[i] == s][0]

print(d[(m-n) % len(d)])