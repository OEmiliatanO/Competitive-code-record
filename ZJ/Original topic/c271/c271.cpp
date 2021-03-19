#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
*/
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
using tiii = tuple<int, int, int>;

constexpr int MAXN = 1001;
constexpr int64 INF = 0x7f7f7f7f7f7f7f7f;
int T, N, W, S, L, h;
tiii arr[MAXN];
int64 DP[MAXN];

auto cmp = [](const tiii& lhs, const tiii& rhs) {
	return (get<2>(lhs) < get<2>(rhs)) | (get<2>(lhs) == get<2>(rhs) && get<1>(lhs) < get<1>(rhs));
};

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);

		for (int i = 1; i <= N; ++i)
		{
			scanf("%d %d %d", &W, &S, &L);
			arr[i] = tiii{ W, S, L };
		}

		sort(arr + 1, arr + 1 + N, cmp);
		memset(DP, 0x7f, sizeof(int64) * MAXN);

		DP[0] = 0, h = 0;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = h + 1; j >= 1; --j)
				if (DP[j - 1] + get<0>(arr[i]) <= get<1>(arr[i]))
					DP[j] = min(DP[j], DP[j - 1] + get<0>(arr[i]));

			h += (DP[h + 1] != INF);
		}

		printf("%d\n", h);
	}

	return 0;
}
