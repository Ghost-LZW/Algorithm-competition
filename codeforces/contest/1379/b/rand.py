from random import randint
l = randint(1, 20)
r = randint(l, 40)
n = randint(1, 40)
m = 0
print(1)
while True :
    a = randint(l, r)
    b = randint(l, r)
    c = randint(l, r)
    m = n * a + b - c
    if m >= 1 :
        break
print(l, r, m)

