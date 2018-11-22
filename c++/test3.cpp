#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1E6;
int ia[MAXN];
int ib[MAXN];
int ans[MAXN];

int main()
{
    string sa, sb;
    cin >> sa >> sb;
    if(sa == sb)
    {
        cout << "0";
        return 0;
    }
    int flag = 0;
    int la = sa.size();
    int lb = sb.size();
    if(lb > la || (la == lb && sb > sa))
    {
        swap(sa, sb);
        swap(la, lb);
        flag = 1;
    }
    for(int i = 0; i < la; i++)
        ia[i] = sa[la - i - 1] - '0';
    for(int i = 0; i < lb; i++)
        ib[i] = sb[lb - i - 1] - '0';
    for(int i = 0; i < la; i++)
    {
        ia[i] -= ib[i];
        if(ia[i] < 0)
        {
            ia[i] += 10;
            ia[i + 1]--;
        }
    }
    int j = la - 1;;
    while(ia[j] == 0)
        j--;
    if(flag)
        cout << "-";
    for(;j >= 0; j--)
        printf("%d", ia[j]);
    return 0;
}
