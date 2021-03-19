#pragma warning( disable : 4996 )
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <algorithm>
#include <cmath>

#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-9;
const double PI = acos(-1);

typedef short int16;
typedef unsigned short uint16;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

template <typename T>
T pow_fast(T x, int64 b)
{
	T tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = x * tmp;
		x = x * x;
		b >>= 1;
	}
	return tmp;
}


typedef struct point
{
	int64 x, y;
}pt;

enum{G, D, E};
pt pts[87];
int t, n, block;
int64 area;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		area = 0x7f7f7f7f7f7f7f7f;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld %lld", &pts[i].x, &pts[i].y);

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					int bk;
					int64 tmpAera = abs((pts[j].x - pts[i].x) * (pts[k].y - pts[i].y) - (pts[j].y - pts[i].y) * (pts[k].x - pts[i].x));
					if (tmpAera == 0)
						continue;
					int64 a = (pts[j].x - pts[i].x) * (pts[k].x - pts[i].x) + (pts[j].y - pts[i].y) * (pts[k].y - pts[i].y);
					int64 b = (pts[i].x - pts[j].x) * (pts[k].x - pts[j].x) + (pts[i].y - pts[j].y) * (pts[k].y - pts[j].y);
					int64 c = (pts[i].x - pts[k].x) * (pts[j].x - pts[k].x) + (pts[i].y - pts[k].y) * (pts[j].y - pts[k].y);
					int64 dot = min({ a, b, c });

					if (dot < 0)
						bk = G;
					else if (dot == 0)
						bk = D;
					else
						bk = E;

					if (area > tmpAera)
						block = bk, area = tmpAera;
					else if (area == tmpAera)
						block = min(block, bk);
				}
			}
		}

		printf("Block of ");
		switch (block)
		{
		case G:
			printf("Gold ");
			break;
		case D:
			printf("Diamond ");
			break;
		case E:
			printf("Emerald ");
			break;
		default:
			break;
		}

		if (area & 1)
			printf("%lld.5", area >> 1);
		else
			printf("%lld", area >> 1);
		puts("");
	}
	return 0;
}
