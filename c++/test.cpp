#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int arr[110];
    int n;
    scanf("%d", &n);
    int flag1 = 0, flag2 = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
    if(arr[0] == 1)
        flag1 = 1;
    if(arr[n - 1] == 1000)
        flag2 = 1;
    if(!flag2 && ! flag1 && n <=2)
    {
        printf("0");
        return 0;
    }
    int tmp = 1, cnt = 0, flag = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i - 1] + 1)
            tmp++;
        else
        {
            if(!flag && flag1)
            {
                flag1 = tmp;
                flag = 1;
            }
            tmp = 1;
        }
        cnt = cnt > tmp ? cnt : tmp;
    }
    if(!flag && !flag2)
    {
        printf("%d", cnt - 1);
        return 0;
    }
    if(flag1 && !flag2)
    {
        if(flag1 - 1 > cnt - 2)
        {
            printf("%d", flag1 - 1);
            return 0;
        }
    }
    else if(flag2 && !flag1)
    {
        if(tmp - 1 > cnt - 2)
        {
            printf("%d", tmp - 1);
            return 0;
        }
    }
    else if(flag1 && flag2)
    {
       cnt = max(flag1 - 1, max(cnt - 2, tmp -1));
       printf("%d", cnt);
       return 0;
    }
    printf("%d", cnt - 2);
    return 0;
}
