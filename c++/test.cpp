#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAXN = 1E5;

char str[MAXN] = "2x^2+3*x+1=0";
char c1[MAXN];
char c2[MAXN];
char c3[MAXN];

int main()
{
   // scanf("%s", str);
    int lenStr = strlen(str);
    int lenX = 0, lenSym = 0;
    for(int i = 0; i < lenStr; i++)
    {
        if(str[i] == 'x')
            lenX++;
        else if(str[i] == '-' || str[i] == '+')
           lenSym++; 
    }

    int fun = 0;
    if(str[0] == '-')
    {
        if(lenX == 2 && lenSym == 3)
            fun = 1;
        else if(lenX == 2 && lenSym == 2)
            fun = 2;
        else if(lenX == 1 && lenSym == 2)
            fun = 3;
        else if(lenX == 1)
        {
            printf("x1=x2=0");            
            return 0;
        }
    }
    else
    {
        if(lenX == 2 && lenSym == 2)
            fun = 4;
        else if(lenX == 2 && lenSym == 1)
            fun = 5;
        else
        {
            printf("x1=x2=0");
            return 0;
        }
    }
    switch(fun)
    {
        case 1:
        case 4:
            sscanf(str, "%[^x]x^2%[^\*]\*x%[^=0]", c1, c2, c3);
            break;
    }
    printf("%s\n%s\n%s\n", c1, c2, c3);
    int a, b, c;
    if(c1[0] == '-')
    {
        c1 = c1.substr(1, len(c1) - 1);
        a = -1 * atoi(c1);
    }
    if(c2[0] == '+')
    {
        
    }
    if(c1 == "")
        printf("1");
    return 0;
}
