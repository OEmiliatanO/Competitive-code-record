#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
*/
//#include <bits/stdc++.h>
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

/**/
#ifdef __GNUC__
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define fread fread_unlocked
#define putchar putchar_unlocked
#else
#define getc getchar
#endif

namespace IO
{
	constexpr int buf_s = 1 << 20;
	static char ch;
	static bool negative;
	inline int getc()
	{
		static char buf[buf_s], * p1 = buf, * p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + read(STDIN_FILENO, buf, buf_s), p1 == p2) ? EOF : *p1++;
	}
	inline int nextInt(int& out)
	{
		if (ch == EOF) return -1;

		static int tmp;
		tmp = 0;
		negative = false;

		ch = getc();
		if (ch != '-' && (ch < '0' || ch > '9'))
			return (ch == EOF ? -1 : ch);
		(ch == '-' ? negative = true : tmp = ch - '0');

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		out = (negative ? -tmp : tmp);

		return 1;
	}
	
	inline int nextChar(char& out)
	{
		ch = getc();
		return (ch == EOF ? -1 : out = ch);
	}

	static char s[25];
	static int16 index;

	inline void printInt64(int64 x)
	{
		if (x == 0) putchar('0');
		negative = (x < 0 && (x = -x));

		index = 0;
		while (x) s[index++] = x % 10 + '0', x /= 10;

		(negative ? s[index++] = '-' : s[index]);

		while (index) putchar(s[--index]);
	}
	inline void printChar(char ch)
	{
		putchar(ch);
	}

	inline void printString(const char* p)
	{
		while (*p)
			putchar(*(p++));
	}

}

using IO::nextInt;
using IO::printInt64;
using IO::nextChar;
using IO::printChar;
using IO::printString;
/**/

/* main code */
#include <queue>

constexpr int MAXN = 1e6;
constexpr int MAXNUM = 1e6 + 1;

int n;
int bucket[MAXNUM];
int64 ans;
int64 qu[2][MAXN + 1];
int Back[2], Front[2];

int main()
{
	while (~nextInt(n) && n)
	{
		memset(bucket, 0, sizeof(int) * MAXNUM);

		Back[0] = Back[1] = Front[0] = Front[1] = ans = 0;

		for (int i = 0, x; i < n; ++i)
		{
			nextInt(x);
			++bucket[x];
		}

		for (int i = 1; i < MAXNUM; ++i)
			while (bucket[i])
				qu[0][Back[0]++] = i, --bucket[i];

		while (Front[0] < Back[0])
		{
			int64 a, b;

			if (Front[1] < Back[1] && qu[0][Front[0]] > qu[1][Front[1]])
				a = qu[1][Front[1]++];
			else
				a = qu[0][Front[0]++];

			if (Front[0] == Back[0])
				b = qu[1][Front[1]++];
			else if (Front[1] < Back[1] && qu[0][Front[0]] > qu[1][Front[1]])
				b = qu[1][Front[1]++];
			else
				b = qu[0][Front[0]++];

			qu[1][Back[1]++] = a + b;
			ans += a + b;
		}

		while (Back[1] - Front[1] >= 2)
		{
			int64 a = qu[1][Front[1]++], b = qu[1][Front[1]++];

			qu[1][Back[1]++] = a + b;
			ans += a + b;
		}

		printInt64(ans);
		printChar('\n');

	}
	return 0;
}