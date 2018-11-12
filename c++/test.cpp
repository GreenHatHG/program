#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e4;
int v[MAXN];
int w[MAXN];
double y[MAXN];
int n, m;

bool fun(double x)
{
    for(int i = 0; i < n; i++)
        y[i] = v[i] - x*w[i];
    sort(y, y + n);
    double sum = 0;
    
    for(int i = 0; i < n - m; i++)
        sum += y[n - i - 1];
    /*
    for(int i = n - 1; i > m - 1; i--)
        sum += y[i];*/
    return sum >= 0;    
}

void solve()
{
    double l = 0, r = 1e10;
    for(int i = 0 ; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if(fun(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.0lf\n", r * 100);
}
int main()
{
    while(scanf("%d %d", &n, &m)&& n && m)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        solve();
    }
    return 0;
}
