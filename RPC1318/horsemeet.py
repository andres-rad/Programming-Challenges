suma = sum(map(int, input().split()))
suma += sum(map(int, input().split()))
print('white' if suma%2 == 1 else 'black')