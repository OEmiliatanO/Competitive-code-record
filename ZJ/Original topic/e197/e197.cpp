#pragma warning( disable : 4996 )
#include <cstdio>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

constexpr int MAXM = 1e5 + 1;
int T, N, M;
long long ans;
pair<int, int> d[MAXM];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < M; ++i)
			scanf("%d", &d[i].first);

		for (int i = 0; i < M; ++i)
			scanf("%d", &d[i].second);

		sort(d, d + M, greater<pii>());

		for (int i = 0; i < M; ++i)
			if (d[i].second > 0)
			{
				ans += ((d[i].second >> 1) + (d[i].second & 0x1)) * d[i].first;
				d[i + 1].second -= (d[i].second & 0x1);
			}

		printf("%lld\n", ans << 1);
	}
	return 0;
}
