#include <cstdio>

using namespace std;

const bool C = 0, V = 1;
int n, mayWay, indexOf_nowWay, minStep;
bool ways[6001][10001];
bool nowWay[10001];

void dfs(int now, int nowClones)
{
    if(now > n) return;
    if(now == n)
    {
        if(indexOf_nowWay > minStep) return;
        if(minStep > indexOf_nowWay)
            minStep = indexOf_nowWay, mayWay = 0;
        for(int i = 0; i < indexOf_nowWay; i++)
            ways[mayWay][i] = nowWay[i];
        mayWay++;
    }

    if(now != nowClones && now + now <= n)
    {
        nowWay[indexOf_nowWay++] = C;
        nowWay[indexOf_nowWay++] = V;
        dfs(now + now, now);
        indexOf_nowWay--;
        indexOf_nowWay--;
    }
    if(now + nowClones <= n)
    {
        nowWay[indexOf_nowWay++] = V;
        dfs(now + nowClones, nowClones);
        indexOf_nowWay--;
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        indexOf_nowWay = mayWay = 0;
        minStep = 0x7f7f7f7f;

        dfs(1, 1);

        printf("min : %d\n", minStep + 1);
        printf("way : %d\n", mayWay);
        for(int i = 0; i < mayWay; putchar('\n'), i++)
        {
            printf("Ctrl C");
            for(int j = 0; j < minStep; j++)
            {
                printf(" + ");
                putchar((ways[i][j] == C ? 'C' : 'V'));
            }
        }
        putchar('\n');
    }
    return 0;
}
