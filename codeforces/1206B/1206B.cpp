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

int64 n, x, ans = 0, ncnt = 0, nsum = 0, maxnag = -1e9 - 1, zcnt = 0;

int main()
{
	scanf("%lld", &n);

	while (n--)
	{
		scanf("%lld", &x);

		if (x > 0)
			ans += x - 1;
		else if (x < 0)
			++ncnt, nsum += x, maxnag = max(maxnag, x);
		else
			++zcnt;
	}

	if (ncnt & 1)
	{
		if (zcnt) printf("%lld", ans - nsum - ncnt + zcnt);
		else printf("%lld", ans - nsum - ncnt + 2);
	}
	else
		printf("%lld", ans - nsum - ncnt + zcnt);

	return 0;
}
