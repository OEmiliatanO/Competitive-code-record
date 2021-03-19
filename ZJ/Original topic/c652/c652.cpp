#pragma warning( disable : 4996 )
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
/*
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;

/* main code */
constexpr int MAXN = 300001;

auto lson = [](int x) { return x << 1; };
auto rson = [](int x) { return x << 1 | 1; };
uint N, Q, ql, qr;

uint64 arr[MAXN], Sum[MAXN * 4], Max[MAXN * 4];
uint64 initMax(int l, int r, int nowNode)
{
	if (l == r)
	{
		Max[nowNode] = arr[l];
		return arr[l];
	}

	int mid = (l + r) >> 1;
	Max[nowNode] = max<uint64>(initMax(l, mid, nowNode << 1), initMax(mid + 1, r, nowNode << 1 | 1));

	return Max[nowNode];
}
uint64 initSum(int l, int r, int nowNode)
{
	if (l == r)
	{
		Sum[nowNode] = arr[l];
		return arr[l];
	}

	int mid = (l + r) >> 1;
	Sum[nowNode] = initSum(l, mid, nowNode << 1) + initSum(mid + 1, r, nowNode << 1 | 1);

	return Sum[nowNode];
}

void updata_range(int l, int r, int nowNode)
{
	if (Max[nowNode] <= 1) return;

	uint64 tmp;
	int mid;
	if (l == r)
	{
		tmp = arr[l] - (uint64)sqrt(arr[l]);
		Sum[nowNode >> 1] -= tmp; 
		arr[l] -= tmp;
		Sum[nowNode] = Max[nowNode] = arr[l];
		return;
	}
	tmp = Sum[nowNode];
	mid = (l + r) >> 1;
	if (ql <= mid) updata_range(l, mid, nowNode << 1);
	if (qr >= mid + 1) updata_range(mid + 1, r, nowNode << 1 | 1);

	Max[nowNode] = max<uint64>(Max[nowNode << 1], Max[nowNode << 1 | 1]);
	Sum[nowNode >> 1] -= (tmp - Sum[nowNode]);
}

uint64 query_Sum(int l, int r, int nowNode)
{
	if (ql <= l && qr >= r) return Sum[nowNode];
	int mid = (l + r) >> 1;
	
	uint64 res = 0;
	if (ql <= mid) res += query_Sum(l, mid, nowNode << 1);
	if (qr >= mid + 1) res += query_Sum(mid + 1, r, nowNode << 1 | 1);
	
	return res;
}

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

	inline int nextUint32(uint& out)
	{
		if (ch == EOF) return -1;

		static uint tmp;
		tmp = 0;

		while ((ch = getc()) && ch >= '0' && ch <= '9')
			tmp = tmp * 10 + ch - '0';

		out = tmp;

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


}
using IO::nextUint32;

using IO::nextUint64;
using IO::printUint64;

using IO::nextDouble;

using IO::nextChar;
using IO::printChar;

int main()
{
	nextUint32(N);
	nextUint32(Q);

	for (int i = 1; i <= N; ++i)
		nextUint64(arr[i]);
	initMax(1, N, 1);
	initSum(1, N, 1);
	for (uint i = 0, op; i < Q; ++i)
	{
		nextUint32(op);
		nextUint32(ql);
		nextUint32(qr);
		if (op == 0)
		{
			printUint64(query_Sum(1, N, 1));
			putchar('\n');
		}
		else
			updata_range(1, N, 1);
	}

	return 0;
}

