import os
import time

source = ['./notes']
target_dir = ['./backup']
target = target_dir + os.sep + \
        time.strftime('%Y%M%D%H%S') + '.zip'

if not os.path.exist(target_dir):
    os.mkdir(target_dir)

zip_command = 'zip -r {0} {1}'.format(target, 
        ' '.join(source))

print('Zip command is:')
print(zip_command)
print('Running:')

if os.system(zip_command) == 0:
    print('Successful backup to', target)
else:
    print('backup fail')

