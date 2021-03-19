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
#include <random>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
int m;
double r;
FILE *in, *ans;

int main()
{
	random_device rd;
	default_random_engine gen = default_random_engine(rd());
	uniform_real_distribution<double> dis(0.0, 92.3);
	uniform_int_distribution<int> mdis(10, 9230);

	in = fopen("e304_00.in.txt", "w");
	ans = fopen("e304_00.out.txt", "w");

	int T = 100;
	for (int i = 0; i < T; ++i)
	{
		r = dis(gen);
		m = mdis(gen);
		printf("'in' file:\n");
		printf("%f %d\n", r, m);
		fprintf(in, "%f %d\n", r, m);

		printf("'ans' file:\n");
		printf("%d\n", 1250 % m);
		fprintf(ans, "%d\n", 1250 % m);
	}

	fclose(in);
	fclose(ans);

	return 0;
}
