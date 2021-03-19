#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 100;
int n, p, cnt[100]{}, ans;

int main()
{
    while(~scanf("%d", &n) && n)
    {
        ans = 0;
        while(n-- && scanf("%d", &p))
            ++cnt[p % mod];

        ans += (cnt[0] * (cnt[0] - 1) >> 1) + (cnt[50] * (cnt[50] - 1) >> 1);

        cnt[0] = cnt[50] = 0;
        for(int i = 1; i < 50; ++i)
            ans += cnt[i] * cnt[100 - i], cnt[i] = cnt[100 - i] = 0;

        printf("%d\n", ans);

        memset(cnt, 0, sizeof(int) * 100);
    }
    return 0;
}
