res = [0.0, 1.0, 1.7, 2.0, 2.3, 2.7, 3.0, 3.3, 3.7, 4.0, 4.3]
lim = [-1, 59, 61, 64, 66, 69, 74, 79, 84, 89, 94]

for _ in range(int(input())) :
    n = int(input())
    if n <= 59 :
        print(0)
    else :
        ans = 0
        while n > 59 :
            ind = 1
            while ind <= 10 and n > lim[ind] :
                ind += 1
            ans += res[ind - 1]
            n -= lim[ind - 1]
        print(ans)
        
    
