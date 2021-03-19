#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
constexpr int MAXN = 2e5;

int n, k;
char s[MAXN + 2];
int pos[MAXN + 2];
int64 dp[MAXN + 2]{};

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);

	pos[n + 1] = 3 * n;
	for (int i = n; i; --i)
		pos[i] = (s[i] == '1' ? i : pos[i + 1]);

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + i;

		int tmp = pos[max(1, i - k)];
		if (tmp <= i + k)
			dp[i] = min(dp[i], dp[max(1, tmp - k) - 1] + tmp);
	}

	printf("%lld\n", dp[n]);

	return 0;
}