from random import randint
l = randint(1, 400)
pre = ''
for i in range(l) :
    pre += chr(randint(97, 122))
print(pre)
