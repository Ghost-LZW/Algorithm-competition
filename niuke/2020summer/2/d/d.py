import datetime, time
res = input()
now = time.strptime(res, "%H:%M:%S")
res = input()
nex = time.strptime(res, "%H:%M:%S")
print(abs(int(time.mktime(nex) - time.mktime(now))))
