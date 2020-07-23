from math import gcd

while True :
    try :
        a = input()
        b = input()
        la = len(a)
        lb = len(b)
        c = la * lb // gcd(la, lb)
        a = a * (c // la)
        b = b * (c // lb)
        if a > b :
            print('>')
        elif a < b :
            print('<')
        else :
            print('=')
    except EOFError :
        break
