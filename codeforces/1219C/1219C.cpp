﻿#pragma warning( disable : 4996 )
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

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-9;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
#include <iostream>
#include <string>

int L;
string s;

int main()
{
	cin >> L >> s;
	int n = s.size();

	if (n % L || count(s.begin(), s.end(), '9') == n)
	{
		string res = '1' + string(L - 1, '0');
		string out;

		while (out.size() < (n % L ? (n + L - 1) / L * L : n + L)) out += res;
		
		cout << out;
	}
	else
	{
		string res = s.substr(0, L);
		string out;
		while (out.size() < n) out += res;

		if (out > s)
			cout << out;
		else
		{
			auto it = res.end();
			--it;
			while (*it == '9')
				*it = '0', --it;
			++(*it);

			out.clear();

			while (out.size() < n) out += res;

			cout << out;
		}
	}

	return 0;
}
