content = open('ans1.txt')
cnt = 0
lines = content.readlines()
print(len(lines))
for i in range(len(lines)) :
    if lines[i][:-1].isdigit() :
        cnt += 1
    if (cnt == 4171) :
        print(i)
        break
content.close()
