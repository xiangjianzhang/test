##########################################################################
# File Name: format_code_style.sh
# Author: jianzhang
# mail: xiangjzh@sugon.com
# Created Time: 2020年07月16日 星期四 17时11分41秒
#########################################################################
#!/bin/bash

for file in `find $1 -name *.[ch]`
do
    echo $file
    dos2unix $file
done

