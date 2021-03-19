#include <cstdio>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<short, short> psh;

enum{BLOCK = -2, EMPTY};

const short dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 1002;

short n, nexi, nexj, nowi, nowj;
int maze[MAXN][MAXN], m;
bool vis[MAXN][MAXN]{};
queue<psh> qu;
gp_hash_table<int, int> TP;

void bfs(short staI = 1, short staJ = 1)
{
    maze[staI][staJ] = 0;

    qu.emplace(psh{staI, staJ});

    while(qu.size())
    {
        if(qu.front().first == n - 2 && qu.front().second == n - 2)
            break;
        nowi = qu.front().first, nowj = qu.front().second; qu.pop();

        for(short i = 0; i < 4; ++i)
        {
            nexi = nowi + dir[i][0], nexj = nowj + dir[i][1];
            if(maze[nexi][nexj] == EMPTY && !vis[nexi][nexj])
            {
                if(TP.find(nexi * n + nexj) != TP.end())
                {
                    vis[nexi][nexj] = true;
                    int tmp = TP[nexi * n + nexj];
                    nexi = tmp / n, nexj = tmp - tmp / n * n;
                }
                qu.emplace(psh{nexi, nexj});
                maze[nexi][nexj] = maze[nowi][nowj] + 1;
            }
        }
        if(TP.find(nowi * n + nowj) != TP.end())
            maze[nowi][nowj] = EMPTY;
    }
}

int main()
{
    scanf("%hd %d", &n, &m); getchar();

    for(short i = 0; i < n; getchar(), ++i)
        for(short j = 0; j < n; ++j)
            maze[i][j] = (getchar() == '#' ? BLOCK : EMPTY);
    for(int i = 0, a, b, c, d; i < m && scanf("%d %d %d %d", &a, &b, &c, &d); ++i)
        TP[a * n + b] = c * n + d, TP[c * n + d] = a * n + b;

    bfs();
    printf("%d", maze[n - 2][n - 2]);
    return 0;
}
