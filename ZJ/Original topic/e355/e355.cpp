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
#include <random>

uint T = 900000;

uint64 n, m, k, ret, squ;
FILE* readFile, * writeFile;

int main()
{
	readFile = fopen("e355_02.in.txt", "w");
	writeFile = fopen("e355_02.out.txt", "w");
	
	random_device rd;
	default_random_engine gen = default_random_engine(rd());
	uniform_int_distribution<uint64> NM_range(1, 10000);
	
	while (T--)
	{
		n = NM_range(gen);
		m = NM_range(gen);

		fprintf(readFile, "%llu %llu\n", n, m);
		//printf("%llu %llu\n", n, m);

		k = min(n, m);
		squ = k * n * m  + (k - 1) * k * (2 * k - 1) / 6 - (m + n) * k * (k - 1) / 2;
		ret = n * m * (n + 1) * (m + 1) / 4 - squ;
		
		fprintf(writeFile, "%llu %llu\n", squ, ret);
		//printf("%llu %llu\n", squ, ret);
	}

	return 0;
}
/*
import sys

for s in sys.stdin:
	k = 0
	m, n = [int(x) for x in s.strip().split()]
	k = min(m, n)

	if m == n == 0:
		break

	ans = k * n * m - (m + n) * k * (k - 1) // 2 + (k - 1) * k * (2 * k - 1) // 6
	ret = n * m * (n + 1) * (m + 1) // 4 - ans
	print("{} {}".format(ans, ret))

*/

/*
#pragma warning( disable : 4996 )

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")

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

uint64 n, m, k, ret, squ;

int main()
{
	while (~scanf("%llu %llu", &n, &m))
	{
		k = min(n, m);
		squ = k * n * m + (k - 1) * k * (2 * k - 1) / 6 - (m + n) * k * (k - 1) / 2;
		ret = n * m * (n + 1) * (m + 1) / 4 - squ;

		printf("%llu %llu\n", squ, ret);
	}

	return 0;
}
*/