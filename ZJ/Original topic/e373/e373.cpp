// e373.cpp
#pragma warning( disable : 4996 )
#include <cstdio>
#include <algorithm>

using namespace std;

using int64 = long long;
using uint64 = unsigned long long;

int64 a, b, c, p;

int64 w = 0;

struct com
{
	int64 integer, sqtw;
	com(void) : integer(1), sqtw(0) {};
	com(int64 a = 1) : integer(a), sqtw(0) {};
	com(int64 a = 1, int64 b = 0) : integer(a), sqtw(b) {};

	com operator *(const com& rhs)
	{
		return com(integer * rhs.integer + sqtw * rhs.sqtw * w, integer * rhs.sqtw + sqtw * rhs.integer);
	}
	com operator %(const int64 m)
	{
		return com(integer % m, sqtw % m);
	}
};

/* fast power */
template <typename T>
T pow_fast(T x, int64 b, int64 m, T se) noexcept
{
	T tmp = se;

	while (b)
	{
		if (b & 0x1) tmp = x % m * tmp % m;
		x = x % m * x % m;
		b >>= 1;
	}
	return tmp % m;
}

/* random */
static inline uint64 rotl(const uint64 x, int k)
{
	return (x << k) | (x >> (64 - k));
}
static uint64 seed[2]{923, 923127};

uint64 random()
{
	uint64 s0 = seed[0], s1 = seed[1], res = s0 + s1;
	s1 ^= s0;
	seed[0] = rotl(s0, 24) ^ s1 ^ (s1 << 16);
	seed[1] = rotl(s1, 37);
	return res;
}

int main()
{
	while (~scanf("%lld %lld %lld %lld", &p, &a, &b, &c))
	{
		a %= p, b %= p, c %= p;
		if (p == 2)
		{
			if (c == 0)
				printf("0 ");
			if ((a + b + c) % p == 0)
				printf("1\n");
			continue;
		}

		//x^2 = n mod p
		int64 n = b * b - 4 * a * c;
		n = (n % p + p) % p;

		if (pow_fast(n, (p - 1) >> 1, p ,1LL) + 1 == p)
		{
			puts("no solution");
			continue;
		}

		while (true)
		{
			int64 a = static_cast<int64>(random()) % p;

			w = (a * a % p - n);
			w = (w % p + p) % p;
			if (pow_fast(w, (p - 1) >> 1, p, 1LL) + 1 == p)
				break;
		}

		//a + 1 * sqrt(w);
		com tmp = com(a, 1);

		//printf("debug %lld %lld\n", (tmp * tmp).integer, (tmp * tmp).sqtw);

		com ans = pow_fast(tmp, (p + 1) >> 1, p, com(1, 0));

		int64 r1 = ans.integer, r2 = p - a;
		int64 inver2a = pow_fast(a, p - 2, p, 1LL);
		inver2a = (inver2a % p + p) % p;
		int64 x1 = (r1 - b) % p, x2 = (r2 - b) % p;
		x1 = (x1 + p) % p; x2 = (x2 + p) % p;
		x1 = x1 * inver2a % p, x2 = x2 * inver2a % p;

		if (x1 == x2)
		{
			printf("%lld\n", x1);
			continue;
		}

		if (x1 > x2) swap(x1, x2);
		printf("%lld %lld\n", x1, x2);
	}
	return 0;
}
