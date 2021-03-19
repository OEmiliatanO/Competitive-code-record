#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define FORR(i, r, l) for (int i =(r); i >= (l); --i)
#define P(STR) puts(#STR)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-8;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

/* mods */

/* main code */
#include <queue>
#include <vector>

constexpr int MAXN = 50;

int t;
int n;
vector<int> position[3];
vector<int> pos[MAXN][3];
int Lim[3];
enum { X, Y, Z };

int state[MAXN * 2 + 1][MAXN * 2 + 1][MAXN * 2 + 1];
enum { Undefined, Soild, Visited };

constexpr int dx[] = {0, 0, 0, 0, -1, 1};
constexpr int dy[] = {0, 0, -1, 1, 0, 0};
constexpr int dz[] = {-1, 1, 0, 0, 0, 0};

struct point
{
	int x, y, z;
	point() = default;
	point(int x0, int y0, int z0) : x(x0), y(y0), z(z0) {};

	point next(int i)
	{
		return point(x + dx[i], y + dy[i], z + dz[i]);
	}

	int vol()
	{
		return (position[X][x + 1] - position[X][x]) * (position[Y][y + 1] - position[Y][y]) * (position[Z][z + 1] - position[Z][z]);
	}

	bool inside()
	{
		return (x >= 0 && x < Lim[X] - 1 && y >= 0 && y < Lim[Y] - 1 && z >= 0 && z < Lim[Z] - 1);
	}

	int area(int i)
	{
		if (dx[i] != 0)
			return (position[Y][y + 1] - position[Y][y]) * (position[Z][z + 1] - position[Z][z]);
		else if (dy[i] != 0)
			return (position[X][x + 1] - position[X][x]) * (position[Z][z + 1] - position[Z][z]);
		else
			return (position[X][x + 1] - position[X][x]) * (position[Y][y + 1] - position[Y][y]);
	}
};

int ansV, ansA;
void bfs()
{
	ansV = ansA = 0;

	point now(0, 0, 0);
	queue<point> qu;

	qu.emplace(now);
	state[now.x][now.y][now.z] = Visited;

	while (qu.size())
	{
		now = qu.front(); qu.pop();

		ansV += now.vol();

		FOR(i, 0, 6)
		{
			point nex = now.next(i);
			if (!nex.inside()) continue;

			if (state[nex.x][nex.y][nex.z] == Soild)
				ansA += now.area(i);
			else if (state[nex.x][nex.y][nex.z] != Visited)
			{
				qu.emplace(nex);
				state[nex.x][nex.y][nex.z] = Visited;
			}
		}
	}

	ansV = 1001 * 1001 * 1001 - ansV;
}

int main()
{
	scanf("%d", &t);

	while (t--)
	{	
		scanf("%d", &n);

		memset(state, Undefined, sizeof(int) * (MAXN * 2 + 1) * (MAXN * 2 + 1) * (MAXN * 2 + 1));
		FOR(i, X, Z + 1)
		{
			FOR(j, 0, n)
				pos[j][i].clear();

			position[i].clear();

			position[i].emplace_back(0);
			position[i].emplace_back(1001);
		}


		FOR(i, 0, n)
		{
			int x0, y0, z0, x, y, z;
			scanf("%d %d %d %d %d %d", &x0, &y0, &z0, &x, &y, &z);

			pos[i][X].emplace_back(x0); pos[i][X].emplace_back(x0 + x);
			pos[i][Y].emplace_back(y0); pos[i][Y].emplace_back(y0 + y);
			pos[i][Z].emplace_back(z0); pos[i][Z].emplace_back(z0 + z);

			position[X].emplace_back(x0); position[X].emplace_back(x0 + x);
			position[Y].emplace_back(y0); position[Y].emplace_back(y0 + y);
			position[Z].emplace_back(z0); position[Z].emplace_back(z0 + z);
		}

		FOR(i, X, Z + 1)
		{
			sort(position[i].begin(), position[i].end());
			Lim[i] = unique(position[i].begin(), position[i].end()) - position[i].begin();
		}

		FOR(i, 0, n)
		{
			int id[3][2];
			FOR(idx, X, Z + 1)
			{
				id[idx][0] = lower_bound(position[idx].begin(), position[idx].begin() + Lim[idx], pos[i][idx][0]) - position[idx].begin();
				id[idx][1] = lower_bound(position[idx].begin(), position[idx].begin() + Lim[idx], pos[i][idx][1]) - position[idx].begin();
			}

			FOR(x, id[X][0], id[X][1])
				FOR(y, id[Y][0], id[Y][1])
					FOR(z, id[Z][0], id[Z][1])
						state[x][y][z] = Soild;
		}

		bfs();

		printf("%d %d\n", ansA, ansV);
	}

	return 0;
}
