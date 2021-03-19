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
#include <vector>
#include <unordered_map>

constexpr int MAXN = 1e5;

vector<int> G[MAXN];
unordered_map<string, int> reName;
int index = 0, now;

string name[MAXN];
string format[MAXN];
int fa[MAXN];

enum {Father, Child};
int oper[2]{-1, -1};

string command, Fname, Fformat;
string lastcopycut;

int convert(string name)
{
	if (reName[name])
		return reName[name];
	return reName[name] = index++;
}

void dfs(int now)
{

}

int main()
{
	now = convert("C");
	name[now] = "C";
	format[now] = "FOLD";
	fa[now] = -1;

	while (cin >> command)
	{
		if (command == "show")
		{
			cout << name[now] << ":" << '\n';

			for (auto it : G[now])
				cout << "-" << name[it] << '\n';

			if (!G[now].size())
				cout << "-(None)" << '\n';
		}
		else if (command == "create")
		{
			bool _exist = false;

			cin >> Fname >> Fformat;

			for (auto it : G[now])
				if (name[it] == Fname)
				{
					_exist = true;
					break;
				}

			if (!_exist)
			{
				G[now].emplace_back(convert(Fname));
				name[convert(Fname)] = Fname;
				format[convert(Fname)] = Fformat;
				fa[convert(Fname)] = now;
			}
		}
		else if (command == "move")
		{
			cin >> Fname;

			for (auto it: G[now])
				if (name[it] == Fname)
				{
					now = it;
					break;
				}
		}
		else if (command == "return")
		{
			if (fa[now] == -1) continue;

			now = fa[now];
		}
		else if (command == "copy" || command == "cut")
		{
			cin >> Fname;

			for (auto it : G[now])
			{
				if (name[it] == Fname)
				{
					lastcopycut = command;
					oper[Father] = now;
					oper[Child] = it;
					break;
				}
			}

		}
		else if(command == "pasta")
		{
			if (lastcopycut == "copy" && oper[Child] != -1)
			{

			}
			else if(lastcopycut == "cut" && oper[Father] != -1 && oper[Child] != -1)
			{
				bool _exist = false;
				
				for (auto it : G[now])
				{
					if (name[it] == name[oper[Child]])
					{
						_exist = true;
						break;
					}
				}

				if (!_exist)
				{

				}
			}
		}
	}

	return 0;
}
