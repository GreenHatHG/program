#include <cstdio>
#include <regex.h>
using namespace std;

const int MAXN = 1e3;
int main()
{
   // char pattern[MAXN] = "\\d*(?=x\\^2)";
    char pattern[MAXN] = "\\d";
    char text[MAXN] = "4x^2+23*x+1=0";
    int flag = REG_EXTENDED;
    regex_t reg;
    regcomp(&reg, pattern, flag);
    regmatch_t pmatch[5];
    int status = regexec(&reg, text, 5, pmatch, 0);
    int j = 0;
    for(int i = pmatch[j].rm_so; i < pmatch[j].rm_eo && j < 5; i++, j++)
    {
        printf("%c", text[i]);
    }
    return 0;
}
