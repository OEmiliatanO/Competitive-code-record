#include <cstdio>
#include <cstring>
#include <queue>
#include <cassert>

using namespace std;

const int MAXN = 2000;

int N, M, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int space[MAXN][MAXN], ans = 0;
bool vis[MAXN][MAXN]{}, ok;

void dfs(const int nowi, const int nowj)
{
    assert(nowi >= 1 && nowi <= N && nowj >= 1 && nowj <= M);
    if(vis[nowi][nowj])
        return;

    int nexi, nexj;

    vis[nowi][nowj] = true;

    for(int i = 0; i < 4; ++i)
    {
        nexi = dir[i][0] + nowi;
        nexj = dir[i][1] + nowj;
        assert(nexi >= 0 && nexi <= N + 1 && nexj >= 0 && nexj <= M + 1);
        if(!vis[nexi][nexj] && space[nexi][nexj] == space[nowi][nowj])
            dfs(nexi, nexj);
        ok &= (space[nexi][nexj] <= space[nowi][nowj]);
    }

}

int main()
{
    scanf("%d %d", &N, &M);
    assert(N <= 1024 && M <= 1024 && N >= 0 && M >= 0);

    for(int i = 0; i <= N + 1; ++i)
        vis[i][0] = vis[i][M + 1] = true, space[i][0] = space[i][M + 1] = -1;
    for(int i = 0; i <= M + 1; ++i)
        vis[0][i] = vis[N + 1][i] = true, space[0][i] = space[N + 1][i] = -1;

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M && scanf("%d", &space[i][j]); assert(space[i][j] >= 0), ++j);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
        {
            if(!vis[i][j])
            {
                ok = true;
                dfs(i, j);
                ans += ok;
            }
        }

    printf("%d", ans);
    return 0;
}
