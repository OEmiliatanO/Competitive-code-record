#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int64;
typedef pair<int, int> pii;

typedef struct _node
{
	int x, y;
	int64 d;

	bool operator < (const _node& a) const
	{return d < a.d;}
}node;

priority_queue< pair<int, int> > pq;
int T, n, X, Y, del;
int64 sum, ans;
node arr[100001];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = sum = 0;

		scanf("%d", &n);
		for (int i = 0; i < n && scanf("%d %d %lld", &arr[i].x, &arr[i].y, &arr[i].d); ++i);
		sort(arr, arr + n);

		for (int i = 0; i < n; ++i)
		{
			sum += (int64)arr[i].x * arr[i].y;
			pq.emplace( pii{ arr[i].y, arr[i].x } );

			while (sum > arr[i].d)
			{
				X = pq.top().second;
				Y = pq.top().first;
				pq.pop();

				del = min<int64>((sum - arr[i].d - 1) / Y + 1, X);
				sum -= (int64)del * Y;
				if (del < X)
					pq.emplace( pii{ Y, X - del } );
			}
		}

		while (pq.size())
		{
			ans += pq.top().second;
			pq.pop();
		}
		printf("%lld\n", ans);
	}
}
