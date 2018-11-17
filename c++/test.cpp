#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 10;
ll ans[MAXN] = {0};
ll flag[MAXN] = {0};
multimap<ll, ll>m;

int main()
{
    ll n;
    scanf("%lld", &n);
    ll tmp, sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        m.insert(pair<ll,ll>(tmp ,i+1));
        sum += tmp;
    }
    multimap<ll, ll>::iterator it;
    ll len = 0;
    for(it = m.begin(); it != m.end(); it++)
    {
        ll t = sum - it->first;
        if(t % 2 == 0 && flag[it->first] == 0)
        {
            multimap<ll, ll>::iterator pos = m.find((ll)t/2);
            if(pos->second != it->second && pos != m.end() )
            {
                flag[it->first] = 1;
                len += m.count(it->first);
            }
        }
    }
    printf("%lld\n", len);
    for(it = m.begin(); it != m.end(); it++)
    {
        if(flag[it->first])
            printf("%lld ", it->second);
    }
    return 0;
}
