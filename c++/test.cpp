#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 120;
int arr[MAXN];

//初始化，即求出对应的素因子
void init()
{
    for(int i = 1; i <= 101; i++)
        arr[i] = i;
    for(int i = 2; i <= 101; i++)
    {
        for(int j = i + 1; j <= 101; j++)
        {
            if(arr[j] % arr[i] == 0)//能被前面整除时，可以被替代
                arr[j] /= arr[i];
        }
    }
    /*
    for(int i = 1; i <= 101; i++)
        cout << ans[i] << " ";
    */
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    int n;
    while(cin >> n)
    {
        int ans[MAXN] = {0};
        ans[0] = 1;
        for(int i = 2; i <= n; i++)//模拟大数乘法
        {
            int c = 0;
            for(int j = 0; j < i; j++)
            {
                int tmp = ans[j] * arr[i] + c; 
                ans[j] = tmp % 10;
                c = tmp / 10; //进位
            }
        }

        int pos = 0;//因为前面有多余的前导0，故需要找到合适的位置再输出
        for(pos = 100; pos >= 0; pos--)
        {
            if(ans[pos])
                break;
        }
        for(int i = pos; i >= 0; i--) //结果是倒序保存的
           cout << ans[i];
    }
    return 0;
}
