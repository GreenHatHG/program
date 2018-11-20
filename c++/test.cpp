#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 1E6;
ll arr[MAXN];
int main()
{
    int n, m, l, cnt = 0;
    scanf("%d %d %d", &n, &m, &l);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", arr+i);
        if(arr[i-1] <= l && arr[i] > l)
            cnt++;
    }
    int q, p, d;
    while(m--)
    {
        scanf("%d", &q);
        if(q == 0)
            printf("%d\n", cnt);
        else
        {
            scanf("%d %d", &p, &d);
            if(arr[p] <= l && (arr[p]+d) > l)
            {
                if(arr[p-1] <= l && arr[p+1]<= l)
                    cnt++;
                else if(arr[p-1] > l && arr[p+1] > l)
                    cnt--;
            }
            arr[p] += d;
        }
    }
    return 0;
}
