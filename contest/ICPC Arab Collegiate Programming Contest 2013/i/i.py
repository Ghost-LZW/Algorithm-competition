import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    n, m = R()
    mz = [[0] * (m + 2) for i in range(n + 2)]
    su = [[0] * (m + 2) for i in range(n + 2)]
    for i in range(1, n + 1) :
        mz[i] = [0] + list(R()) + [0]
    ans = - float('inf')
    for i in range(n, 0, -1) : 
        for j in range(m, 0, -1) :
            su[i][j] = mz[i][j] + su[i][j + 1] + su[i + 1][j] - su[i + 1][j + 1]
            ans = max(ans, su[i][j])
    print(ans)
