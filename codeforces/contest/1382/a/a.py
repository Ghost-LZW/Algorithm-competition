for _ in range(int(input())) :
    input()
    a = set(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = -1
    for i in b :
        if i in a :
            ans = i
            break
    if ans == -1 :
        print("NO")
    else :
        print("YES")
        print("1", ans)
