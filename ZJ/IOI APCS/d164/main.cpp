#include <cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

const int MAXN = 10001;

int N, M, arr[MAXN], l ,r, ans, nex;

int main()
{
    while(~scanf("%d %d", &N, &M))
    {
        ans = l = 0, r = -1;
        for(int i = 0; i < N && scanf("%d", arr + i); ++i);
        while(r - l + 1 != M) ans += arr[++r];

        nex = ans + arr[(r + 1) % N] - arr[l];
        ans = max(ans, nex);
        ++r, ++l;
        r %= N, l %= N;

        while(r != M - 1)
        {
            nex = nex + arr[(r + 1) % N] - arr[l];
            ans = max(ans, nex);
            ++r, ++l;
            r %= N, l %= N;
        }
        printf("%d\n", ans);
    }
    return 0;
}
