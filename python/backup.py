import os
import time
import sys
import re


target_dir = './backup'
target = target_dir + '.txt' 

if not os.path.exists(target_dir):
    os.mkdir(target_dir)

for i in sys.argv:
    print(i)

str = ''
if sys.argv[1] == 'mail':
    str += 'mail'
elif sys.argv[1] == 'phone':
    str += 'phone'
else:
    print('wrong parameter')
str += ' '
str += sys.argv[2] 
str += '\r\n'
print(str)

fd = open(target, 'a+')
fd.seek(0, 0)
matchObj = False
print('check item exist:')
for line in fd.readlines():                        
    line = line.strip(); 
    print(line)                             
    matchObj = re.search( line, "%s" %  str, re.M | re.I)
    print(matchObj)
    if matchObj:
        print(line)
if not matchObj:
    fd.write(str)
fd.close()
print('write done')


