#include <cstdio>
#include <cstring>

using namespace std;

int limit[20][20], N;
char way[20], last[20];
int next[20];

void DFS(int now, int pos)
{
    int a, pre = 0;
    if(now == 0)
    {
        for(a = 0; a < pos; a++)
        {
            if(way[a] - 1 + 'A' != last[a])
                last[a] = way[a] - 1 + 'A', putchar(last[a]);
        }
        puts("");
        return;
    }
    for(a = next[0]; a; pre = a, a = next[a])
        if(!limit[a][pos])
        {
            next[pre] = next[a];
            way[pos] = a;
            DFS(now - 1, pos + 1);
            next[pre] = a;
        }
}
int main()
{
    int a, x;

    while(~scanf("%d", &N))
    {
        for(a = 0; a < N; a++)
            next[a] = a+1;

        memset(last, 0, sizeof(last));
        memset(limit, 0, sizeof(limit));

        for(a = 1; a <= N; a++)
        {
            while(scanf("%d", &x) && x != 0)
                limit[a][x-1] = 1;
        }
        next[N] = 0;
        DFS(N, 0);
    }
    return 0;
}
