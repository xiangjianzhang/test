
##########################################################################
# File Name: format_code_style.sh
# Author: jianzhang
# mail: xiangjzh@sugon.com
# Created Time: 2020年07月16日 星期四 17时11分41秒
#########################################################################

#!/bin/bash
file=$2
dir=$1
while read line
do
    parttern1=$(echo $line | awk '{print $1}')
    parttern2=$(echo $line | awk '{print $2}')
    for file in `find $dir -name *.[ch]`
    do
        echo "sed -i 's/$parttern1/$parttern2/g' $file"
        sed -i "s/$parttern1/$parttern2/g" $file
    done
done  < $2

