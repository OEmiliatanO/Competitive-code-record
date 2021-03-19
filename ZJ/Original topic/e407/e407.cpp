#pragma warning( disable : 4996 )
#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using pii = pair<long long, long long>;

int q, op;
long long c;
priority_queue<pii, vector<pii>, greater<pii> > pq, tmp;
vector<pii> Qu;
int Index = 0;
long long padd = 0;
int ans;

int main()
{
	scanf("%d", &q);

	for (int i = 1; i <= q; ++i)
	{
		scanf("%d %lld", &op, &c);

		if (op == 1)
		{
			pq.emplace(c + padd, i);
			Qu.emplace_back(i, c + padd);
		}
		else if (op == 2)
		{
			padd += c;

			while (Index < Qu.size() && Qu[Index].second <= padd)
				++Index;
			while (Index < Qu.size() && pq.size() && pq.top().first <= padd)
			{
				tmp.emplace(pq.top().second, pq.top().first);
				pq.pop();
			}
			while (tmp.size() && (Index == Qu.size() || tmp.top().first <= Qu[Index].first))
				tmp.pop();

			printf("%d\n", tmp.size());
		}
	}

	return 0;
}

