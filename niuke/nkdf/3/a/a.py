def search(n, a) :
    t = set()
    for i in a :
        if i in t :
            return i
        else :
            t.add(i)
print(search(4, [1, 2, 1, 4, 3]))
