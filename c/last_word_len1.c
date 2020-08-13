/*************************************************************************
 *  > File Name: last_word_len.c
 *  > Author: jianzhang
 *  > Mail: xiang.jianzhang@163.com
 *  > Created Time: 2020年04月18日 星期六 14时16分29秒
 *************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 5000

#ifndef u32
#    define u32 unsigned int
#    define u8  unsigned char
#    define u16 unsigned short
#    define s32 int
#    define s8  char
#    define s16 short
#endif

u32 get_last_word_len(char *str)
{
    char *p = str;
    u32 len = 0;

    if(NULL == str) {
        return 0;
    }

    len = strlen(str);
    if(0 == len)
        return 0;

    p += len;

    while((str != p) && (' ' != *p)) {
        p--;
    }

    if(' ' == *p) {
        p++;
    }
    return strlen(p);
}

int main(int argc, char *argv[])
{

    char *input = (char *)malloc(MAX_LEN);
    gets(input);
    printf("%d\n", get_last_word_len(input));

    return 0;
}
