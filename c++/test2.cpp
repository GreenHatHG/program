#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1e6;
int ia[MAXN];
int ib[MAXN];
int ans[MAXN];

int main()
{
    string sa, sb;
    cin >> sa >> sb;
    int la = sa.size();
    int lb = sb.size();
    int ml = la > lb ? la : lb;
    for(int i = 0; i < la; i++)
        ia[i] = sa[la - i - 1] - '0';
    for(int i = 0; i < lb; i++)
        ib[i] = sb[lb - i - 1] - '0';
    int next = 0;
    for(int i = 0; i < ml; i++)
    {
        ans[i] = (ia[i] + ib[i] + next) % 10;
        next = (ia[i] + ib[i] + next) / 10;
    }
    if(next > 0)
        cout << next;
    for(int i = ml - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}
