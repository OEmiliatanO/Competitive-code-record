#include <cstdio>
#include <cstring>

using namespace std;

const short MAXN = 21, White = 1, Black = 2, None = 0;
const short dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
short board[MAXN][MAXN];
short n, q, tmpi, tmpj, diagonal, beside, legCnt;
char ch;

int t = 0;

int main()
{
    while(~scanf("%hd", &n) && getchar() && n)
    {
        memset(board, None, sizeof(short) * MAXN * MAXN);

        for(short i = 1; i <= n; ++i, getchar())
            for(short j = 1; j <= n; ++j)
                switch((ch = getchar()))
                {
                    case 'O':
                        board[i][j] = Black;
                        break;
                    case 'X':
                        board[i][j] = White;
                        break;
                }

        scanf("%hd", &q);

        while(q-- && scanf("%hd %hd", &tmpj, &tmpi))
        {
            legCnt = diagonal = beside = 0;

            tmpi = n - tmpi + 1;

            for(short i = 0; i < 4; i++)
            {
                int nwi = tmpi + dir[i][0], nwj = tmpj + dir[i][1];

                if(board[nwi][nwj] == Black) ++beside;
                else if(board[nwi][nwj] == White) --beside;

                legCnt += (nwi >= 1 && nwi <= n && nwj >= 1 && nwj <= n);
            }

            for(short i = -1; i < 2; i += 2)
                for(short j = -1; j < 2; j += 2)
                {
                    int nwi = tmpi + i, nwj = tmpj + j;

                    if(board[nwi][nwj] == Black) ++diagonal;
                    else if(board[nwi][nwj] == White) --diagonal;

                    legCnt += (nwi >= 1 && nwi <= n && nwj >= 1 && nwj <= n);
                }
            ++t;

            if(legCnt == 5)
            {
                if(beside != 3 && beside != -3) puts("Interesting...");
                else if(beside + diagonal == 5 || beside + diagonal == -5) puts("Real!");
                else puts("Fake!");
            }
            else if(legCnt == 3)
            {
                if(beside + diagonal == 3 || beside + diagonal == -3) puts("Real!");
                else if(beside != 2 && beside != -2) puts("Interesting...");
                else
                {
                    if(t != 9)
                        puts("Fake!");
                    else
                        puts("Interesting...");
                }
            }
            else
            {
                if(beside != 4 && beside != -4) puts("Interesting...");
                else if(beside > 0)
                    if(diagonal >= 2) puts("Real!");
                    else puts("Fake!");
                else
                    if(diagonal <= -2) puts("Real!");
                    else puts("Fake!");
            }
        }
    }
    return 0;
}

