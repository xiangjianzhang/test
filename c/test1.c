/*************************************************************************
	> File Name: test1.c
	> Author: jianzhang
	> Mail: xiang.jianzhang@163.com 
	> Created Time: 2020年04月19日 星期日 16时38分16秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define u32 unsigned int 
#define u16 unsigned short
#define u8  unsigned char 


struct  shaizi 
{
	u8 st_l; 
	u8 st_r; 
	u8 st_f;
	u8 st_b;
	u8 st_s;
	u8 st_x;
};




void show_result(struct shaizi *sh)
{
		printf("%d", sh->st_l);
		printf("%d", sh->st_r);
		printf("%d", sh->st_f);
		printf("%d", sh->st_b);
		printf("%d", sh->st_s);
		printf("%d", sh->st_x);
		printf("\n");
}


int move(char a, struct shaizi *sh)
{
	u8 tmp;
	switch (a)
	{
		case 'L':
			tmp = sh->st_l;
			sh->st_l = sh->st_f;
			sh->st_f = sh->st_r;
			sh->st_r = sh->st_b;
			sh->st_b = tmp;
			break;
		case 'R':
			tmp = sh->st_l;
			sh->st_l = sh->st_b;
			sh->st_b = sh->st_r;
			sh->st_r = sh->st_f;
			sh->st_f = tmp;
			break;
		case 'F':
			tmp = sh->st_f;
			sh->st_f = sh->st_s;
			sh->st_s = sh->st_b;
			sh->st_b = sh->st_x;
			sh->st_x = tmp;
			break;
		case 'B':
			tmp = sh->st_f;
			sh->st_f = sh->st_x;
			sh->st_x = sh->st_b;
			sh->st_b = sh->st_s;
			sh->st_s = tmp;
			break;
		case 'A':
			tmp = sh->st_s;
			sh->st_s = sh->st_r;
			sh->st_r = sh->st_x;
			sh->st_x = sh->st_l;
			sh->st_l = tmp;
			break;
		case 'C':
			tmp = sh->st_s;
			sh->st_s = sh->st_l;
			sh->st_l = sh->st_x;
			sh->st_x = sh->st_r;
			sh->st_r = tmp;
			break;
		default:
			return -1;

	}
	return 0;
}


int main(int argc, char *argv[])
{
	struct shaizi sh;
	char action[1000];
	char *cur;

    sh.st_l = 1;
    sh.st_r = 2;
    sh.st_f = 3;
    sh.st_b = 4;
    sh.st_s = 5;
    sh.st_x = 6;

	show_result(&sh);
	while (fgets(action, 1000, stdin))
	{
		action[strlen(action) - 1] = '\0';
		cur = action;
		while(*cur != '\0')
		{
			move(*cur, &sh);
			cur++;
		}
		show_result(&sh);
	}


	return 0;
}
