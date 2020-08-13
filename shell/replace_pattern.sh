
##########################################################################
# File Name: format_code_style.sh
# Author: jianzhang
# mail: xiangjzh@sugon.com
# Created Time: 2020年07月16日 星期四 17时11分41秒
#########################################################################

parttern1=$2
parttern2=$3
for file in `find $1 -name *.[ch]`
do
    echo "sed -i 's/$parttern1/$parttern2/g' $file"
    sed -i "s/$parttern1/$parttern2/g" $file
done


