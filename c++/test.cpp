#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1E6;
int pre[MAXN], Max[MAXN], num[MAXN];

int Find(int x)
{
    int p = x, tmp;
    while(x != pre[x])
        x = pre[x];
    while(p != x)
    {
        tmp = pre[p];
        pre[p] = x;
        p = tmp;
    }
    return x;
}

void join(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y)
    {
        pre[x] = y;
        Max[y] = Max[x] > Max[y] ? Max[x] : Max[y];
        num[y] += num[x];
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        pre[i] = i;
        Max[i] = 1;
        num[i] = 1;
    }
    int x, y;
    int cnt = n;
    char s[10];
    while(m--)
    {
        scanf("%s", s);
        if(strcmp(s, "union") == 0)
        {
            scanf("%d%d", &x, &y);
            if(Find(x) != Find(y))
            {
                join(x, y);
                cnt--;
            }
        }
        else if(strcmp(s, "same") == 0)
        {
            scanf("%d%d", &x, &y);
            if(Find(x) == Find(y))
                printf("1\n");
            else
                printf("0\n");
        }   
        else if(strcmp(s, "setnum") == 0)
        {
            printf("%d\n", cnt);
        }
        else if(strcmp(s, "max") == 0)
        {
            scanf("%d", &x);
            printf("%d\n", Max[Find(x)]); 
        }
        else
        {
            scanf("%d", &x);
            printf("%d\n", num[Find(x)]);
        }
    }
    return 0;
}
