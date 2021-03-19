#include <cstdio>

using namespace std;

const int MAXN = 100001, mod = 1234567;
int N, M, x, sol[MAXN] = {0, 1};

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N && scanf("%d", &M); ++i)
    {
        for(int j = 1; j <= M && scanf("%d", &x); ++j)
        {
            sol[x] += sol[i];
            sol[x] %= mod;
        }
    }
    printf("%d\n", sol[N]);

    return 0;
}
