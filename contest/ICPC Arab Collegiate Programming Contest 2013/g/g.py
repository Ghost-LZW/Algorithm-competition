import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    n, m, x = R()
    if (n % m == x % m) : print("YES")
    else : print("NO")
