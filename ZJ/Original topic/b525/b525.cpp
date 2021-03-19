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
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */

struct mat
{
	int64 m00, m01, m10, m11;
	mat(int64 a, int64 b, int64 c, int64 d) :m00(a), m01(b), m10(c), m11(d) {};
	mat() {};

	mat operator*(const mat& B) const
	{
		int64 r00, r01, r10, r11;
		
		r00 = (m00 * B.m00) % 100000007 + (m01 * B.m10) % 100000007;
		r01 = (m00 * B.m10) % 100000007 + (m01 * B.m11) % 100000007;

		r10 = (m10 * B.m00) % 100000007 + (m11 * B.m10) % 100000007;
		r11 = (m10 * B.m10) % 100000007 + (m11 * B.m11) % 100000007;

		return mat(r00 % 100000007, r01 % 100000007, r10 % 100000007, r11 % 100000007);
	}
};

int m, f, k;

int64 g(int n)
{
	if (n == 0) return f;
	else if (n == 1) return f + m;
	else
	{
		mat res(0, 0, 0, 0);
		mat x(1, 1, 1, 0);

		n -= 1;
		while (n)
		{
			if (n & 0x1)
				if (res.m00 == 0)
					res = x;
				else
					res = res * x;

			x = x * x;
			n >>= 1;
		}

		return ((f + m) * res.m00 % 100000007 + f * res.m01 % 100000007) % 100000007;
	}
}

int main()
{
	while (~scanf("%d %d %d", &m, &f, &k))
		printf("%lld\n", (g(k) + g(k - 1)) % 100000007);

	return 0;
}
