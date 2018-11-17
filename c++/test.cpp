#include <cstdio>
#include <map>
using namespace std;

const int MAXN = 1e6 + 10;
int ans[MAXN] = {0};
multimap<int, int>m;

int main()
{
    int n;
    scanf("%d", &n);
    int tmp, sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        m.insert(pair<int,int>(tmp ,i+1));
        sum += tmp;
    }
    multimap<int, int>::iterator it;
    int len = 0;
    for(it = m.begin(); it != m.end(); it++)
    {
        int t = sum - it->first;
        if(t % 2 != 0 && ans[it->first] == 0)
            continue;
        multimap<int, int>::iterator pos = m.find(t/2);
        if(pos->second != it->second && pos != m.end() )
        {
            ans[it->first] = m.count(it->first);
            len++;
        }
    }
    printf("%d\n", len);
    for(int i = 0; i < MAXN; i++)
    {
        if(ans[i] > 0)
            printf("%d ", i);
    }
    return 0;
}
