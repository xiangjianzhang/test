/**
* Copyright (C), 2020, Sugon Information Industry Co., Ltd.
*
* @file    huge_page.c
* @author  向建章
* @date:    2020.08.11
* @brief:  简介
* @note:   初版
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>


#define MAP_LENGTH (2*1024*1024)

int main()
{
    int fd;
    void * addr;

    /* create a file in hugetlb fs */
    fd = open("/mnt/huge/test", O_CREAT | O_RDWR);
    if(fd < 0){
        perror("open: ");
        return -1;
    }

    /* map the file into address space of current application process */
    addr = mmap(0, MAP_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED){
        perror("mmap: ");
        close(fd);
        unlink("/mnt/huge/test");
        return -1;
    }

    /* from now on, you can store application data on huage pages via addr */

    munmap(addr, MAP_LENGTH);
    close(fd);
    unlink("/mnt/huge/test");
    return 0;
}
