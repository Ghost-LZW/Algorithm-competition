import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    n = int(input())
    a = input() + '0'
    b = input() + '0'
    ad, bd = [], []
    for i in range(1, n + 1) :
        if a[i] != a[i - 1] :
            ad.append(i)
        if b[i] != b[i - 1] :
            bd.append(i)
    ad += bd[::-1]
    print(len(ad), *ad)
