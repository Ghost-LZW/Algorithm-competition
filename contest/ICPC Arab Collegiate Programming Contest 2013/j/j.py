import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())

x, y, d = 0, 0, 0

def exgcd(a, b) :
    global x, y, d
    if b == 0 :
        x, y, d = 1, 0, a
        return 
    exgcd(b, a % b)
    x, y = y, x - a // b * y

for _ in range(int(input())) :
    n1, a1, d1, n2, a2, d2 = R()
    exgcd(d1, -d2)
    res = a2 - a1
    x *= res // d
    y *= res // d
    d = abs(d)
    dx, dy = d2 // d, d1 // d
    while x >= 0 and y >= 0 :
        x -= dx
        y -= dy
    while x < 0 or y < 0 :
        x += dx
        y += dy
    print(min((n1 - 1 - x) // dx, (n2 - 1 - y) // dy) + 1)
