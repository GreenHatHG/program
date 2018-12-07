/*
Submit Time: 12-07 16:13
Exe.Time: 78ms
Exe.Memory: 15.96MB
*/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1100;
int Vis[MAXN][MAXN];
char Map[MAXN][MAXN];
int Step[MAXN][MAXN];
int Path[MAXN][MAXN];
char str[] = {"DLRU"};

int dir[4][2] =
{
    {1,0},
    {0,-1},
    {0,1},
    {-1,0}
};

struct point{
    int x, y;
}in, out, beg;

int n, m;
int check(int x, int y)
{
    if(!Vis[x][y] && x >= 1 && y >= 1 
            && x <= n && y <= m && Map[x][y] != '1')
        return 1;
    return 0;
}

int bfs()
{
    memset(Vis, 0, sizeof(Vis));
    memset(Step, 0, sizeof(Vis));
    Vis[beg.x][beg.y] = 1;
    Step[beg.x][beg.y] = 0;
    queue<point>q;
    q.push(beg);
    while(!q.empty())
    {
        out = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            in.x = out.x + dir[i][0];
            in.y = out.y + dir[i][1];
            if(check(in.x, in.y))
            {
                Path[in.x][in.y] = i;
                if(in.x == n && in.y == m)
                    return Step[out.x][out.y] + 1;
                q.push(in);
                Vis[in.x][in.y] = 1;
                Step[in.x][in.y] = Step[out.x][out.y] + 1;
            }
        }
    }
    return 0;
}

void printPath(int x, int y)
{
    if(x == 1 && y == 1)
        return;
    printPath(x - dir[Path[x][y]][0], y - dir[Path[x][y]][1]);
    printf("%c", str[Path[x][y]]);
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        getchar();
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                scanf("%c", &Map[i][j]);
            getchar();
        }
        beg.x = 1;
        beg.y = 1;
        printf("%d\n", bfs());
        printPath(n, m);
        printf("\n");
    }
    return 0;
}
