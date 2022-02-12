input()
n, k = map(int, input().split())
a = []
b = []
for i in range(n // 2):
    a.append(list(map(int, input().split())))
    b.extend(a[-1])
b.sort()
assert b == list(range(n))
x = 0
for k1, k2 in a :
    x += k1 & k2
assert x == k

