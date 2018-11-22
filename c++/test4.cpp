#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1E3;
int ia[MAXN];
int ib[MAXN];
int ic[MAXN];

int main()
{
    string sa, sb;
    cin >> sa >> sb;
    int la = sa.size();
    int lb = sb.size();
    memset(ia, 0, sizeof(ia));
    memset(ib, 0, sizeof(ib));
    if(lb > la || (lb == la && lb > la))
    {
        swap(sa, sb);
        swap(la, lb);
    }
    for(int i = 0; i < la; i++)
        ia[i] = sa[la - i - 1] - '0';
    for(int i = 0; i < lb; i++)
        ib[i] = sb[lb - i - 1] - '0';
    for(int i = 0; i < lb; i++)
    {
        for(int j = 0; j < la; j++)
        {
            ic[i + j] = ic[i + j] + ia[j] * ib[i];
        }
    }

    for(int i = 0; i < 2 * la; i++)
    {
        if(ic[i] > 10)
        {
            ic[i + 1] = ic[i + 1] + ic[i] / 10;
            ic[i] = ic[i] % 10;
        }
    }

    int j = 2 * la;
    while(ic[j] == 0)
        j--;
    if(j < 0)
    {
        cout << "0";
        return 0;
    }
    for(;j >= 0; j--)
        cout << ic[j];
    return 0;
}
