#include <iostream>
using namespace std;
const int MAXN = 120;
int ans[MAXN];

void init()
{
    for(int i = 1; i <= 101; i++)
        ans[i] = i;
    for(int i = 2; i <= 101; i++)
    {
        for(int j = i + 1; j <= 101; j++)
        {
            if(ans[j] % ans[i] == 0)
                ans[j] /= ans[i];
        }
    }
    for(int i = 1; i <= 101; i++)
        cout << ans[i] << " ";
}
int main()
{
    init();
    return 0;
}
