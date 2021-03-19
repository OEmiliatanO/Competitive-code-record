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
	#ifdef __GNUC__
	inline int getc()
	{
		static char buf[buf_s], * p1 = buf, * p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + read(STDIN_FILENO, buf, buf_s), p1 == p2) ? EOF : *p1++;
	}
	#endif
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
	inline int nextUint(uint& out)
	{
		if (ch == EOF) return -1;

		static uint tmp;
		tmp = 0;

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		out = tmp;

		return 1;
	}

	inline int nextInt64(int64& out)
	{
		if (ch == EOF) return -1;

		static int64 tmp;
		tmp = 0;
		negative = false;

		ch = getc();
		if (ch != '-' && (ch < '0' || ch > '9'))
			return (ch == EOF ? -1 : ch);
		(ch == '-' ? negative = true : tmp = (int64)ch - '0');

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		out = (negative ? -tmp : tmp);

		return 1;
	}
	inline int nextUint64(uint64& out)
	{
		if (ch == EOF) return -1;

		static uint64 tmp;
		tmp = 0;

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		out = tmp;
		return 1;
	}

	inline int nextDouble(double& out)
	{
		if (ch == EOF) return -1;

		static double tmp;
		double len = 0.1;
		negative = false;

		tmp = 0.0;

		ch = getc();
		if (ch != '-' && (ch < '0' || ch > '9'))
			return (ch == EOF ? -1 : ch);
		(ch == '-' ? negative = true : tmp = (double)ch - '0');

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		if (ch == '.')
			while ((ch = getc()) && ch >= '0' && ch <= '9')
				tmp += (double)(ch - '0') * len, len *= 0.1;

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
	inline void printInt(int x)
	{
		if (x == 0) putchar('0');
		negative = (x < 0 && (x = -x));

		index = 0;
		while (x) s[index++] = x % 10 + '0', x /= 10;

		(negative ? s[index++] = '-' : s[index]);

		while (index) putchar(s[--index]);
	}
	inline void printUint(uint x)
	{
		if (x == 0) putchar('0');

		index = 0;
		while (x) s[index++] = x % 10 + '0', x /= 10;

		while (index) putchar(s[--index]);
	}

	inline void printInt64(int64 x)
	{
		if (x == 0) putchar('0');
		negative = (x < 0 && (x = -x));

		index = 0;
		while (x) s[index++] = x % 10 + '0', x /= 10;

		(negative ? s[index++] = '-' : s[index]);

		while (index) putchar(s[--index]);
	}
	inline void printUint64(uint64 x)
	{
		if (x == 0) putchar('0');

		index = 0;
		while (x) s[index++] = x % 10 + '0', x /= 10;

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
using IO::printInt;

using IO::nextUint;
using IO::printUint;

using IO::nextInt64;
using IO::printInt64;

using IO::nextUint64;
using IO::printUint64;

using IO::nextDouble;

using IO::nextChar;
using IO::printChar;
using IO::printString;

/* main code */

short arr[11]{ 1,2,3,4,5,6,7,8,9,10 };
int n;

int main()
{
	nextInt(n);

	do
	{
		FOR(i, 0, n)
		{
			printInt(*(arr + i));
			printChar(' ');
		}
		printChar('\n');

	} while (next_permutation(arr, arr + n));


	return 0;
}
