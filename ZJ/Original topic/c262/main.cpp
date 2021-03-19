#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n, m, q, a, b, c;
bool wi[501][501];

int main()
{
    while(~scanf("%d %d %d", &n, &m, &q) && (n || m || q))
    {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                wi[i][j] = wi[j][i] = (i == j);

        for(int i = 0; i < m && scanf("%d %d %d", &a, &b, &c); ++i)
        {
            if(q < c) wi[a][b] = wi[b][a] = false;
            else wi[a][b] = wi[b][a] = true;
        }

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    wi[j][i] = wi[i][j] = (wi[i][j] || (wi[i][k] && wi[k][j]));

        puts((!wi[1][n] ? "GG" : "Save"));
    }
    return 0;
}
