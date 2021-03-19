#include <cstdio>

using namespace std;

const int MAXN = 500001;
int f[MAXN];
int n;

int main()
{
    f[1] = 1;
    for(int i = 2; i < MAXN; ++i)
        if(i & 1) f[i] = (f[(i >> 1) + 1] - 1)  << 1;
        else f[i] = f[i >> 1] << 1;

    while(~scanf("%d", &n) && n)
        printf("%d\n", f[n]);
    return 0;
}
