import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    s = input()
    x, y, t = 0, 0, 0
    for i in s :
        if i == 'U' : y += 1
        if i == 'D' : y -= 1
        if i == 'L' : x -= 1
        if i == 'R' : x += 1
        if i == '?' : t += 1
    print(x - t, y - t, x + t, y + t)
