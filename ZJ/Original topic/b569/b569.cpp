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
constexpr int MAXN = 10000000;

char s[2][MAXN + 1];
int len;
bool a[MAXN + 1];

int main()
{
	scanf("%s %s", s[0], s[1]);

	len = strlen(s[0]);

	for (int i = 0; i < len; ++i)
		a[i] = (s[0][i] - '0') ^ (s[1][i] - '0');

	bool zeroOccur = false;
	bool isTheFirstZero = false;
	for (int i = 0; i < len; ++i)
	{
		zeroOccur |= !a[i];
		if (zeroOccur && !isTheFirstZero) a[i] = true, isTheFirstZero = true;
		if (!zeroOccur) putchar(s[0][i]);
		else
			putchar((a[i] ^ (s[0][i] - '0')) + '0');
	}

	return 0;
}
