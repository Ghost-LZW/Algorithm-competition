for _ in range(int(input())) :
    a, b, c, d = map(int, input().split())
    k1, k2 = b - a, d - c
    if k1 == k2 :
        if k1 > 0 :
            print("AB//DC")
        else :
            print("AB//CD")
    else if k1 == -k2 :
        
