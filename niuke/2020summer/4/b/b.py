from math import log

for _ in range(int(input())) :
    x, c = map(int, input().split())
    print(c ** int(log(x, 2)))
