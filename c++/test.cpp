#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e2;

int sub(int *num1, int len1, int *num2, int len2)
{
    if(len1 < len2)
        return -1;

    if(len1 == len2)
    {
        for(int i = len1 - 1; i >= 0; i--)
        {
            if(num1[i] > num2[i])
                break;
            else if(num1[i] < num2[i])
                return -1;
        }
    }

    for(int i = 0; i <= len1 - 1; i++)
    {
        num1[i] -= num2[i];
        if(num1[i] < 0)
        {
            num1[i] += 10;
            num1[i + 1]--;
        }
    }

    for(int i = len1 - 1;i >= 0; i--)
    {
        if(num1[i])
            return i + 1;
    }
    return 0;
}

int division(char* num1, char* num2, char* ans)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int num_a[MAXN] = {0};
    int num_b[MAXN] = {0};
    int num_c[MAXN] = {0};

    for(int i = 0; i < len1; i++)
        num_a[i] = num1[len1 - i - 1];
    for(int i = 0; i < len2; i++)
        num_b[i] = num2[len2 - i - 1];

    if(len1 < len2)
        return -1;
    
    int dvalue = len1 - len2;
    for(int i = len1 - 1; i >= 0; i--)
    {
        if(i >= dvalue)
            num_b[i] = num_b[i - dvalue];
        else
            num_b[i] = 0;
    }
    
    len2 = len1;
    int n;
    for(int i = 0; i <= dvalue; i++)
    {
        while((n = sub(num_a, len1, num_b + i, len2 - i)) >= 0)
        {
            len1 = n;
            num_c[dvalue - i]++;
        }
    }
    
    int j;
    for(j = MAXN - 1; j >= 0; j--)
    {
        if(num_c[j] != 0)
            break;
    }
    int len = -1;
    if(j >= 0)
        len = j + 1;
 //   for(int i = 0; j >= 0; i++, j--)
 //       ans[i] = num_c[j] + '0';
    for(int i = 0; i < len ; i++)
        cout << num_c[j];
    ans[j] = '\0';
    return len;
}

int main()
{
    char num1[MAXN] = "1234567899876543210";
    char num2[MAXN] = "20160415123025";
    char ans[MAXN];

    int len = division(num1, num2, ans);
    if(len >= 0)
    {
        for(int i = 0; i < len; i++)
            cout << ans[i];
    }
    else
        cout << "0";
    return 0;
}

