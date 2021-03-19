#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-9;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
#include <vector>

constexpr int MAXN = 1e5;

enum {blue, red, green};

int n, m, setsize[3]{};
int16 color[MAXN + 1]{};
vector<int> G[MAXN + 1];

int main()
{
	scanf("%d %d", &n, &m);
	
	for (int i = 0, a, b; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	setsize[blue] = n;

	for (int i = 1; i <= n; ++i)
	{
		for (auto nex : G[i])
			if (color[nex] == color[i])
			{
				--setsize[color[nex]];
				++color[nex];
				if (color[nex] == 3) color[nex] = green;
				++setsize[color[nex]];
			}
	}

	if (setsize[blue] == 0 || setsize[red] == 0 || setsize[green] == 0)
	{
		puts("-1");
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		if (n - setsize[color[i]] != G[i].size() || G[i].size() == 0)
		{
			puts("-1");
			return 0;
		}

	for (int i = 1; i <= n; ++i)
		printf("%d ", color[i] + 1);

	return 0;
}
