import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    n, x, y = R()
    if y == 1 :
        if x > n :
            print(*range(1, n + 1))
        else :
            print(*range(1, x), *range(x + 1, n + 2))
    else :
        if x > n :
            print(*range(1, n), x)
        else :
            print(*range(1, n + 1))
