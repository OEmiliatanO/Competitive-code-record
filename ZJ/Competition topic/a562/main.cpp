#include <cstdio>
#include <cstring>
#include <cassert>

#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int n, m, arr[10][10], ans, dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool visNum[101];

inline bool in(int i, int j)
{
    return ((i) >= 1 && (i) <= m && (j) >= 1 && (j) <= m);
}

void dfs(int i, int j, int step)
{
    ans = max(ans, step);
    visNum[arr[i][j]] = true;
    for(int index = 0; index < 4; index++)
    {
        int nexi = i + dir[index][0], nexj = j + dir[index][1];
        if(in(nexi, nexj) && !visNum[arr[nexi][nexj]])
        {
            dfs(nexi, nexj, step + 1);
        }
    }
    visNum[arr[i][j]] = false;
}

int main()
{
    scanf("%d", &n);
    while(n-- && scanf("%d", &m))
    {
        ans = -1;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &arr[i][j]);
                assert(arr[i][j] <= 100 && arr[i][j] >= 0);
            }
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
            {
                memset(visNum, false, 101);
                dfs(i, j, 1);
            }
        printf("%d\n", ans);
    }
    return 0;
}
