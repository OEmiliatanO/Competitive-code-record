#include <cstdio>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

const int MAXN = 1e5;
int N, arr[MAXN], l , r, ans, c;

int main()
{
    while(~scanf("%d", &N))
    {
        l = N + 1, r = ans = c = 0;
        for(int i = 0; i < N; ++i)
            scanf("%d", arr + i);
        for(int i = 0; i < N; ++i, ++c)
        {
            l = min(l, arr[i]);
            r = max(r, arr[i]);
            ans = max(ans, r - l - c + 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
