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

using int16 = short;
using uint16 = unsigned short;
using int32 = int;
using uint = unsigned int;
using uint32 = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

#define fread fread_unlocked
#define putchar putchar_unlocked
namespace IO
{
	static char ch;
	static bool negative;
	inline int getc()
	{
		static char buf[1 << 20], * p1 = buf, * p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline int nextInt32(int32& out)
	{
		if (ch == EOF) return -1;

		static int32 tmp;
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
	inline int nextUint32(uint32& out)
	{
		if (ch == EOF) return -1;

		static uint32 tmp;
		tmp = 0;

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		out = tmp;

		if (ch == EOF) return -1;

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

	inline int nextChar(char& out)
	{
		ch = getc();
		return (ch == EOF ? -1 : out = ch);
	}

	static char s[25];
	static int16 index;
	inline void printInt32(int32 x)
	{
		if (x == 0) putchar('0');
		negative = (x < 0 && (x = -x));

		index = 0;
		while (x) s[index++] = x % 10 + '0', x /= 10;

		(negative ? s[index++] = '-' : s[index]);

		while (index) putchar(s[--index]);
	}
	inline void printUint32(uint32 x)
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

using IO::nextInt32;
using IO::printInt32;

using IO::nextUint32;
using IO::printUint32;

using IO::nextInt64;
using IO::printInt64;

using IO::nextUint64;
using IO::printUint64;

using IO::nextChar;
using IO::printChar;
using IO::printString;

/* main code */

bool isParityZero(uint64 x)
{
	for (int i = 32; i; i >>= 1)
		x = x ^ (x >> i);
	return !(x & 1);
}


uint n, arr[2];
uint64 x;

int main()
{
	while (~nextUint32(n))
	{
		arr[0] = arr[1] = 0;
		for (uint i = 0; i < n; ++i)
		{
			nextUint64(x);
			++arr[!isParityZero(x)];
		}
		if (n == 1)
			putchar('0');
		else
		{
			x = (uint64)n * (n - 1) / 2 - arr[0] * arr[1];
			printUint64(x);
		}
		putchar('\n');
	}
	return 0;
}

