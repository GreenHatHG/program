#include <cstdio>

char Map[11][11];
int main()
{
    int n=3, m=3;
    char c;
  //  scanf("%d %d", &n, &m);
//	getchar();
  //  printf("%d%d", n, m);
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
//			scanf("%c", &Map[i][j]);
			scanf("%c", &c);
            printf("%c", c);
		}
		getchar();
	}
}
