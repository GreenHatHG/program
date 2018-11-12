#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5};
    int sum[10] = {0};
    for(int i = 0; i < 5; i++)
        sum[i + 1] = sum[i] + a[i];
    int S = 11;
    int res = 5;
    for(int s = 0; sum[s] + S < sum[5]; s++)
    {
        int t = lower_bound(sum + s, sum + 5, sum[s] + S) - sum;
        cout << "sum[s] + S=" << s << " " << sum[s] + S << endl;
        cout << "t=" << t << endl;
        cout << endl;
        res = min(res, t - s);
    }
    cout << res << endl;
    return 0;
}
