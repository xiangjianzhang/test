/*************************************************************************
	> File Name: test_enc3.c
	> Author: jianzhang
	> Mail: xiang.jianzhang@163.com 
	> Created Time: 2020年04月18日 星期六 17时23分02秒
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
		else if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
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
    aucResult[i] = '\0';
    printf("%s\n", aucResult);
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
		else if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
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
    password[i] = '\0'; 
    printf("%s\n", password);
}


int main(int argc, char *argv[])
{
    char *passwd1, *result1;
    char *passwd2, *result2;
    passwd1 = malloc(200);
    passwd2 = malloc(200);
    result1 = malloc(200);
    result2 = malloc(200);
    while (fgets(passwd1, 101, stdin))
	{
		fgets(passwd2, 101, stdin);
		passwd1[strlen(passwd1) - 1] = '\0';
		passwd2[strlen(passwd2) - 1] = '\0';
		Encrypt(passwd1, result1);
		unEncrypt(passwd2, result2);
	}

    //printf("%s\n", result2);
    
    
    return 0;
}
