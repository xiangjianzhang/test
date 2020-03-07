#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os, sys

# 打开文件
fd = os.open( "foo.txt", os.O_RDWR|os.O_CREAT )

# 写入字符串
ret = os.write(fd, 'This is test'.encode())


# 关闭文件
os.close( fd )

print("关闭文件成功!!")