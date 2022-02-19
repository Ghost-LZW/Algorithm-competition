import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    n, x, y = R()
    a = list(R())
    e, h = a[0] == x, a[n - 1] == y
    print(["OKAY", "HARD", "EASY", "BOTH"][(e << 1) + h])
    

