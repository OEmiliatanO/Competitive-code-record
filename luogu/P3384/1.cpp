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
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-10;
const double PI = acos(-1);

using int16 = int_fast16_t;
using uint16 = uint_fast16_t;
using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = long long;
using uint64 = uint_fast64_t;
using pii = pair<int32, int32>;

/* main code */
constexpr int MAXN = (int)1e5;
int N, M, R, P;
int wi[MAXN];
vector<int> vec[MAXN];
int head[MAXN]{ 0 }, depth[MAXN], parent[MAXN]{ 0 };
int heavySon[MAXN]{ 0 }, treeSize[MAXN]{ 0 };
int cnt = 0, idx[MAXN]{ 0 };
void treeAdd(int, int, int);
int64 treeSum(int, int);
void dfs(int);
void heavylight(int, int);

//zkw


int main()
{
	
	scanf("%d %d %d %d", &N, &M, &R, &P);
	for (int i = 1; i <= N; ++i) scanf("%d", wi + i);
	for (int i = 0, x, y; i < N - 1; ++i)
	{
		scanf("%d %d", &x, &y);
		vec[x].emplace_back(y);
		vec[y].emplace_back(x);
	}

	depth[R] = 1, parent[R] = -1;
	dfs(R);
	heavylight(R, R);

	for (int i = 0, op, x, y, z; i < M; ++i)
	{
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			scanf("%d %d %d", &x, &y, &z);
			treeAdd(x, y, z % P);
			break;
		case 2:
			scanf("%d %d", &x, &y);
			printf("%lld\n", treeSum(x, y));
			break;
		case 3:
			scanf("%d %d", &x, &z);

			//updareRange(idx[x], idx[x] + treeSize[x], z);

			break;
		case 4:
			scanf("%d", &x);
			//printf("%lld\n", sum(idx[x], idx[x] + treeSize[x]));
			break;
		default:
			assert(false);
		}
	}
	
	return 0;
}


void dfs(int now)
{
	int heavy = -1;
	treeSize[now] = 1;
	for (auto it : vec[now])
	{
		if (it == parent[now]) continue;

		parent[it] = now;
		depth[it] = depth[now] + 1;
		dfs(it);
		treeSize[now] += treeSize[it];
		if (treeSize[it] > heavy) heavy = treeSize[it], heavySon[now] = it;
	}
}

void heavylight(int now, int topf)
{
	idx[now] = ++cnt;
	origin[idx[now]] = wi[now];
	head[now] = topf;
	if (!heavySon[now]) return;
	heavylight(heavySon[now], topf);

	for (auto it : vec[now])
	{
		if (!idx[it])
			heavylight(it, it);
	}
}

void treeAdd(int x, int y, int value)
{
	while (head[x] != head[y])
	{
		if (depth[head[x]] < depth[head[y]]) swap(x, y);
		//update(idx[head[x]], value);
		//update(idx[x] + 1, -value);
		x = parent[head[x]];
	}
	if (depth[x] > depth[y]) swap(x, y);
	//update(idx[x], value);
	//update(idx[y] + 1, -value);
}

int64 treeSum(int x, int y)
{
	int64 result = 0;
	while (head[x] != head[y])
	{
		if (depth[head[x]] < depth[head[y]]) swap(x, y);
		//result = (result + sum(idx[head[x]], idx[x])) % P;
		x = parent[head[x]];
	}
	if (depth[x] > depth[y]) swap(x, y);
	//result = (result + sum(idx[x], idx[y])) % P;
	return result;
}