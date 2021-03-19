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

constexpr int MAXN = 4e5;

int n, m, colors[MAXN + 1];
auto convert = [](int x) -> int64 { return (int64)1 << x; };
auto popcnt = [](int64 x) {
	int ans = 0;
	for (; x; x -= x & (-x)) ++ans;
	return ans;
};

vector<int> E[MAXN + 1];
pii dfn[MAXN + 1]{};
int dfncnt = 1, dedfn[MAXN + 1];

void dfs(int);

/* segment tree */
auto ls = [](int x) { return x << 1; };
auto rs = [](int x) { return x << 1 | 1; };

int64 seg[MAXN << 2 | 1], lazy[MAXN << 2 | 1];

void build(int, int, int);
int64 ask(int, int, int, int, int);
void updata(int, int, int, int, int, int);
void maintain(int);
/* */

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &colors[i]);

	for (int i = 0, x, y; i < n - 1; ++i)
	{
		scanf("%d %d", &x, &y);

		E[x].emplace_back(y);
		E[y].emplace_back(x);
	}

	dfs(1);
	build(1, n, 1);

	for(int t, v, c; m--; )
	{
		scanf("%d", &t);

		if (t == 1)
		{
			scanf("%d %d", &v, &c);
			updata(dfn[v].first, dfn[v].second - 1, 1, n, 1, c);
		}
		else
		{
			scanf("%d", &c);
			printf("%d\n", popcnt(ask(dfn[c].first, dfn[c].second - 1, 1, n, 1)));
		}
	}

	return 0;
}

void dfs(int i = 1)
{
	dfn[i].first = dfncnt, dedfn[dfncnt++] = i;
	for (auto nex : E[i])
	{
		if (dfn[nex].first == 0)
			dfs(nex);
	}
	dfn[i].second = dfncnt;
}

void build(int l, int r, int id)
{
	lazy[id] = 0;
	if (l == r) seg[id] = convert(colors[dedfn[l]]);
	else
	{
		int mid = (l + r) >> 1;

		build(l, mid, ls(id));
		build(mid + 1, r, rs(id));

		seg[id] = seg[ls(id)] | seg[rs(id)];
	}
}

void updata(int ql, int qr, int l, int r, int id, int v)
{
	if (ql > r || qr < l)
		return;

	if (ql <= l && qr >= r)
		seg[id] = lazy[id] = convert(v);
	else
	{
		int mid = (l + r) >> 1;

		maintain(id);

		updata(ql, qr, l, mid, ls(id), v);
		updata(ql, qr, mid + 1, r, rs(id), v);

		seg[id] = seg[ls(id)] | seg[rs(id)];
	}
}

int64 ask(int ql, int qr, int l, int r, int id)
{
	if (ql > r || qr < l) return 0;
	
	if (ql <= l && qr >= r) return seg[id];
	
	int mid = (l + r) >> 1;
	maintain(id);

	return ask(ql, qr, l, mid, ls(id)) | ask(ql, qr, mid + 1, r, rs(id));
}

void maintain(int id)
{
	if (lazy[id])
		seg[ls(id)] = seg[rs(id)] = lazy[ls(id)] = lazy[rs(id)] = lazy[id];
	lazy[id] = 0;
}
