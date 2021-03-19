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
#include <cassert>
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
#include <map>
#include <queue>
#include <string>
#include <iostream>

constexpr int MAXPATNUM = 100;

int num_oper, num_recr, stclock, trans_time, prepareOp_time, prepareRe_time, patnum;
map<string, int> nameTonum;
map<int, string> numToname;

enum {inQueue, inOper, Wait, inRecr, Done};
struct patient
{
	int id, op_begin, op_end, re_begin, re_end;
	int room, bed;
	int req_op, req_re;
	int state;

	patient() = default;
	patient(int id, int reqo, int reqr, int st) :id(id), req_op(reqo), req_re(reqr), state(st) {};
};

patient patData[MAXPATNUM + 1];
int oper[11]{};
int operCD[11];
int oper_usetime[11]{};
int recr[31]{};
int recrCD[31];
int recr_usetime[31]{};

bool isAllDnoe()
{
	bool Ok = true;
	FOR(i, 1, patnum + 1)
		Ok &= (patData[i].state == Done);
	return Ok;
}

priority_queue<pii, vector<pii>, greater<pii> > recover_queue;
int nowT = 0;

void init()
{
	nowT = 0;

	memset(oper, 0, sizeof(oper));
	memset(operCD, 0, sizeof(operCD));
	memset(oper_usetime, 0, sizeof(oper_usetime));
	memset(recr, 0, sizeof(recr));
	memset(recrCD, 0, sizeof(recrCD));
	memset(recr_usetime, 0, sizeof(recr_usetime));

	recover_queue = priority_queue<pii, vector<pii>, greater<pii> >();
	nameTonum.clear();
	numToname.clear();
}

int main()
{
	//ios_jazz;

	while (cin >> num_oper >> num_recr >> stclock >> trans_time >> prepareOp_time >> prepareRe_time >> patnum)
	{
		init();

		FOR(id, 1, patnum + 1)
		{
			string name;
			int req_op, req_re;

			cin >> name;
			nameTonum[name] = id;
			numToname[id] = name;

			cin >> req_op >> req_re;
			patData[id] = patient(id, req_op, req_re, inQueue);
		}

		while (not isAllDnoe())
		{
			FOR(i, 1, num_oper + 1)
				if (oper[i] == 0 && operCD[i] <= nowT)
				{
					FOR(j, 1, patnum + 1)
						if (patData[j].state == inQueue)
						{
							oper[i] = patData[j].id;
							oper_usetime[i] += patData[j].req_op;

							patData[j].state = inOper;
							patData[j].op_begin = nowT;
							patData[j].op_end = nowT + patData[j].req_op;
							patData[j].room = i;
							break;
						}
				}
				else
				{
					int id = oper[i];

					if (patData[id].op_end == nowT)
					{
						recover_queue.emplace(i, id);

						patData[id].state = Wait;
						patData[id].re_begin = nowT + trans_time;
						patData[id].re_end = patData[id].re_begin + patData[id].req_re;

						operCD[i] = nowT + prepareOp_time;
						oper[i] = 0;
					}
				}

			FOR(i, 1, num_recr + 1)
			{
				if (recr[i] == 0 && recrCD[i] <= nowT)
				{
					if (recover_queue.empty()) continue;
					int id = recover_queue.top().second; recover_queue.pop();

					recr[i] = id;
					recr_usetime[i] += patData[id].req_re;

					assert(patData[id].state == Wait);

					patData[id].state = inRecr;
					patData[id].bed = i;
				}
				else
				{
					int id = recr[i];

					if (patData[id].re_end == nowT)
					{
						patData[id].state = Done;

						recrCD[i] = nowT + prepareRe_time;
						recr[i] = 0;
					}
				}
			}
			assert(recover_queue.empty());

			++nowT;
		}

		auto convertTime = [=](int t) -> pii {
			int hour = stclock;
			int min = t;
			hour += min / 60;
			min %= 60;
			return { hour, min };
		};

#define br cout << '\n';

		cout << " Patient          Operating Room          Recovery Room" << '\n';
		cout << " #  Name     Room#  Begin   End      Bed#  Begin    End" << '\n';
		cout << " ------------------------------------------------------" << '\n';

		FOR(i, 1, patnum + 1)
		{
			pii roombeg, bedbeg, roomend, bedend;
			int room, bed;

			roombeg = convertTime(patData[i].op_begin);
			bedbeg = convertTime(patData[i].re_begin);
			roomend = convertTime(patData[i].op_end);
			bedend = convertTime(patData[i].re_end);
			room = patData[i].room, bed = patData[i].bed;

			printf("%2d  %-9s %2d  %3d:%02d  %3d:%02d    %3d  %3d:%02d  %3d:%02d\n", i, numToname[i].c_str(), room, roombeg.first, roombeg.second, roomend.first, roomend.second, bed, bedbeg.first, bedbeg.second, bedend.first, bedend.second);

		}
		br;

		--nowT;
		cout << "Facility Utilization" << '\n';
		cout << "Type  # Minutes  % Used" << '\n';
		cout << "-------------------------" << '\n';
		FOR(i, 1, num_oper + 1)
		{
			printf("%-4s %2d %7d %7.2lf\n", "Room", i, oper_usetime[i], (double)oper_usetime[i] * 100 / fabs(nowT));
		}
		FOR(i, 1, num_recr + 1)
		{
			printf("%-4s %2d %7d %7.2lf\n", "Bed", i, recr_usetime[i], (double)recr_usetime[i] * 100 / fabs(nowT));
		}
		br;
	}
	return 0;
}
