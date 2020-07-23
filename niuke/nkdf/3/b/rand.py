from random import randint
n = randint(1, 10)
print(n)
for i in range(2, n + 1) :
    print(randint(1, i - 1), i)
q = randint(1, 5)
print(q)
for i in range(q) :
    print(randint(1, n), randint(-99, 99))
