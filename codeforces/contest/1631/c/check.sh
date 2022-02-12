#########################################################################
# File Name: check.sh
# Author: ghost_lzw
# mail: lanzongwei541@gmail.com
# Created Time: Thu Jan 27 23:37:00 2022
#########################################################################
#!/bin/bash
g++ c.cpp -o my
while true
do
python3 rand.py > rand.in
res=`cat rand.in`
my=`./my < rand.in`
rt=`echo -e "$res\n$my"`
python3 ck.py <<< $rt
if [ $? == 0 ]
then
printf AC
else
echo WA
cat rand.in
exit 0
fi
done

