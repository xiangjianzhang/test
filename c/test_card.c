/*************************************************************************
	> File Name: test_card.c
	> Author: jianzhang
	> Mail: xiang.jianzhang@163.com 
	> Created Time: 2020年04月18日 星期六 19时32分29秒
 ************************************************************************/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


char array[4] = {'+', '-', '*', '/'};

void printf_card(int a)
{
    switch (a) 
    {
        case 1:
            printf("A");
            break;
        case 11:
            printf("J");
            break;
        case 12:
            printf("Q");
            break;
        case 13:
            printf("K");
        default:
            printf("%d", a);
    }
}

void dump_reult(int a, int b, int c, int d, int x, int y, int z)
{
    printf_card(a);
    printf("%c", array[x]);
    printf_card(b);
    printf("%c", array[y]);    
    printf_card(c);
    printf("%c", array[z]);    
    printf_card(d);
	printf("\r\n");
    
}

#define OP_ERROR  2048
int operation(char op, int a, int b)
{
     switch (op) {
         case '+':
             return a + b;
         case '-':
             return a - b;
         case '*':
             return a * b;
         case '/':
             if (b == 0 || a % b != 0) 
             {
                 return  OP_ERROR;
             }
             else 
             {
                 return a / b; 
             }
     }   
    return 0;
}

int  checkSum(int a, int b, int c, int d)
{  
    int a1, b1, c1;
    int i, j,k;
    for (i = 0; i < 4; i++) 
    {
        a1 = operation(array[i], a, b);
        if (OP_ERROR == a1) 
            continue;
        for (j = 0; j < 4; j++) 
        {
            b1 =  operation(array[j], a1, c);
            if (OP_ERROR == b1) 
                continue;
            for (k = 0 ; k < 4; k++)
            {
                c1 =  operation(array[k], b1, d);
                if (OP_ERROR == c1) 
                    continue;
                if (c1 == 24) 
                {
                    dump_reult(a, b, c, d, i, j, k);
					return 0;
                }
            }
        }    
    }
}

void  play_card(int a[])
{
    int i, j, k, z;
    
    for (i = 0; i < 4; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            if (j != i) {
                for (k = 0 ; k < 4; k++)
                {
                   if ((k != i) && (k != j))
                   {
                       for (z = 0; z < 4; z++)
                       {
                           if ((z != i) && (z != j) && (z != k))
                           {
                               if(0 == checkSum(a[i], a[j], a[k], a[z]))
							   {
								   return;
							   }
                           }

                       }  
                   }
                }
            }
        }
        
    }

	printf("NONE\n");
}



int main(int argc, char *argv[])
{
    char input[100] = {0};
    int in[4] = {0};
    char *it = NULL; 
    int i = 0, val = 0;
    
    if (fgets(input, 100, stdin))
    {
        input[strlen(input) -1 ] = '\0';

        for (it = input; *it != '\0'; it++)
        {
			if (*it == ' ')
			{
				continue;
			}
            if((*it == '1') && (*(it + 1) == '0') && (*(it + 2) == ' '))
            {
				it++;
                val = 10;
            }
            else if ((*(it + 1) == '\0') || (*(it + 1) == ' ')) 
            {
                switch (*it) 
                {
                    case '2':
                        val = 2;
                        break;
                    case '3':
                       val = 3; 
                        break;
                    case '4':
                       val = 4; 
                        break;
                    case '5':
                       val = 5; 
                        break;
                    case '6':
                       val = 6; 
                        break;
                    case '7':
                        val = 7;
                        break;
                    case '8':
                        val = 8;
                        break;
                    case '9':
                        val = 9;
                        break;
                    case 'J':
                        val = 11;
                        break;
                    case  'Q':
                        val = 12;
                        break;
                    case 'K':
                        val = 13;
                        break;
                    case 'A':
                        val = 1;
                        break;
                    default:
                        printf("ERROR\n");
                        return 0;
                }
            }
            else
            {
                printf("ERROR\n");
                return 0;
            }
            in[i++] = val; 
        }
        
		play_card(in);   
    }
    return 0;
}


