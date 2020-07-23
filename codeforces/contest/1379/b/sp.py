l, r, m = map(int, input().split())
a, b, c = map(int, input().split())

def ck(t) :
    return t >= l and t <= r

if not (ck(a) and ck(b) and ck(c)) :
    exit(1)

res = m - b + c

if res % a != 0 or res // a <= 0 :
    exit(1)

exit(0)

