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

/* main code */
#include <iostream>
#include <string>
#include <unordered_map>

constexpr int MAXN = 1500;

int n, k;
string s[MAXN + 1];
unordered_map<string, int64> UM;

int main()
{
	ios_jazz;

	int64 ans = 0;

	cin >> n >> k;

	FOR(i, 0, n)
	{
		cin >> s[i];
		++UM[s[i]];
	}

	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			string tmp(k, '0');

			FOR(k, 0, s[i].size())
				if (s[i][k] == s[j][k])
					tmp[k] = s[i][k];
				else
					tmp[k] = 'S' ^ 'E' ^ 'T' ^ s[i][k] ^ s[j][k];

			ans += UM[tmp];
		}
	}

	cout << ans / 3;

	return 0;
}
