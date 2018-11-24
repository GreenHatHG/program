#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;
typedef long long ll;

int area(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int iL= A > E ? A : E;
    int iR = C < G ? C : G;
    int iT= D < H ? D : H;
    int iB = B > F ? B : F;

    int w = iT > iB ? (iT - iB) : 0;
    int h = iR > iL ? (iR - iL) : 0;
    int Area = w * h;

    return Area;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    int col, row;
    int A, B, C, D, E, F, G, H;
    int cntW;
    cin >> n;
    while(n--)
    {
        cin >> col >> row;
        cin >> A >> B >> C >> D >> E >> F >> G >> H;
        ll cnt = col*row;
        cntW = cnt / 2;

        int Area = area(A-1, B-1, C, D, E-1, F-1, G, H);
        cout << Area << endl;
        if(Area == 0)
        {
            for(int i = A; i <= D; i++)
            {
                for(int j = B; j <= C; j++)
                {
                    if((i + j) % 2 != 0)
                        cntW++;
                }
            }
            for(int i = E; i <= H; i++)
            {
                for(int j = F; j <= G; j++)
                {
                    if((i + j) % 2 != 0)
                        cntW--;
                }
            }
            cout << cntW << " " << cnt-cntW << endl;
        }
        else if(Area == cnt)
        {
            cout << "0" << " " << cnt << endl;
        }
        else
        {
            cntW -= Area;
            cout << cntW << " " << cnt - cntW << endl;
        }
    }
    return 0;
}

