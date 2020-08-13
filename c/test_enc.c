/*************************************************************************
	> File Name: test_enc.c
	> Author: jianzhang
	> Mail: xiang.jianzhang@163.com 
	> Created Time: 2020年04月18日 星期六 16时25分35秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char auto_switch(char a)
{
	if ((a >= 'a') && (a <= 'z'))
	{
		a = a - ('a' - 'A');  
	}
	else
	{
		a = a + ('a' - 'A');  
	}
}


void Encrypt (char aucPassword[], char aucResult[])
{
    unsigned int i = 0;
    char c;
    
    while ((c = aucPassword[i]) != '\0')
	{
		if (c >= '0' && c <= '9')
		{
			if ('9' == c)
				c = '0';
			else
				c = c+1;
		}
		else
		{
			if (('Z' == c) || ('z' == c))
			{
				c = (c - ('z' - 'a'));
			}
			else
			{
				c = c + 1;
			}
			c = auto_switch(c);
		}
		aucResult[i] = c; 
		i++;
	}
}

int unEncrypt (char result[], char password[])
{
    unsigned int i = 0;
    char c;
    
    while ((c = result[i]) != '\0')
	{
		if (c >= '0' && c <= '9')
		{
			if ('0' == c)
				c = '9';
			else
				c = c-1;
		}
		else
		{
			if (('a' == c) || ('A' == c))
			{
				c = (c + ('z' - 'a'));
			}
			else
			{
				c = c - 1;
			}
			c = auto_switch(c);
		}
		password[i] = c; 
		i++;
	}
}


int main(int argc, char *argv[])
{
    char *passwd1, *result1;
    char *passwd2, *result2;
    passwd1 = malloc(100);
    passwd2 = malloc(100);
    result1 = malloc(100);
    result2 = malloc(100);
    
    gets(passwd1);
    gets(passwd2);
    Encrypt(passwd1, result1);
    unEncrypt(passwd2, result2);
    
    printf("%s\n", result1);
    printf("%s\n", result2);
    
    
    return 0;
}
