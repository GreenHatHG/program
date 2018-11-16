#include <cstdio>
using namespace std;

int main()
{
    int arr[110];
    int n;
    scanf("%d", &n); 
    int cnt = 0, tmp = 1, flag = 0, tmp2 = -1;
    scanf("%d", &arr[0]);
    if(arr[0] == 1)
        flag = 1;
    for(int i = 1; i < n; i++)
    {
        scanf("%d", arr + i);
        if(arr[i] != 1000)
        {
            if(arr[i] == arr[i-1] + 1)
                tmp++;
            else
            {
                tmp2 = tmp;
                tmp = 1;
            }
            if(flag == 1)
            {
                if(n == 2 && arr[1] == arr[0] + 1)
                {
                    printf("1");
                    return 0;
                }
                if(tmp2 != -1)
                {
                    tmp2 -= 1;
                    flag = tmp2;
                }
                else if(i == n - 1)
                    flag = tmp - 1;
            }
            cnt = cnt > tmp2 ? cnt : tmp2;
            cnt = cnt > tmp ? cnt : tmp;
        }
        else
        {
            if(n == 2)
            {
                printf("1");
                return 0;
            }
            if(arr[n - 2] == 999 && tmp > cnt - 2)
            {
                printf("%d", tmp);
                return 0;
            }
        }
    }
    if(cnt <= 2)
        printf("0");
    else
    {
        if(flag > 1 && flag > cnt - 2)
            printf("%d", flag);
        else
            printf("%d", cnt - 2);
    }
    return 0;
}
