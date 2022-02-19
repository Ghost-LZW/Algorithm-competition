import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
mod = 1000000007
for _ in range(int(input())) :
    s = input()
    pre = -1
    ans = 1
    val = 0
    for i in range(len(s)) :
        if s[i] == '?' :
            val += 1
        else :
            if val:
                if pre != -1 and s[pre] != s[i] :
                        ans *= (val + 1) 
                ans %= mod
                val = 0
            pre = i
    print(ans)
