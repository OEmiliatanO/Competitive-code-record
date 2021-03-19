#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <cstdio>
#include <cstdint>
using namespace std;

using int16 = int_fast16_t;
using int32 = int_fast32_t;
using int64 = int_fast64_t;

#define putchar putchar_unlocked
#define getc getchar_unlocked
namespace IO
{
	static char ch = 0;
	static bool negative;

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
}

using IO::nextInt32;
using IO::printInt32;

/* main code */
int32 N, a, b, c, x;

int main()
{
	nextInt32(N);
	a = b = c = 0;
	while (N-- && nextInt32(x))
	{
		c = x & b;
		b &= ~x;
		x &= ~c;
		b |= a & x;
		a ^= x;
	}
	printInt32(a);

	return 0;
}
