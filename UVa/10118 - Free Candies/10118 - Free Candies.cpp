#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int plie[5][41];
vector<int> hight(5);

int DP[41][41][41][41];

struct Bckt
{
	int bucketCol[25];
	int idx = 0;

	void pop(int col)
	{
		--bucketCol[col];
		--idx;
	}
	void push(int col)
	{
		++bucketCol[col];
		++idx;
	}
};

int dfs(Bckt nowBckt, vector<int> nowHight)
{
	int& ans = DP[nowHight[1]][nowHight[2]][nowHight[3]][nowHight[4]];

	int sum = 0;

	if (ans != -1)
		return ans;

	ans = 0;
	for (int i = 1; i <= 4; ++i)
	{
		if (nowHight[i] == 0) continue;

		int colfromPile = plie[i][nowHight[i]--];

		if (nowBckt.bucketCol[colfromPile] && nowBckt.idx < 5)
		{
			nowBckt.pop(colfromPile);
			sum = dfs(nowBckt, nowHight) + 1;
			nowBckt.push(colfromPile);
		}
		else if (nowBckt.idx < 5)
		{
			nowBckt.push(colfromPile);
			sum = dfs(nowBckt, nowHight);
			nowBckt.pop(colfromPile);
		}

		ans = max(ans, sum);

		++nowHight[i];
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	Bckt st;
	for (int i = 1; i <= 20; ++i)
		st.bucketCol[i] = 0;
	st.idx = 0;

	while (cin >> n, n)
	{
		memset(DP, -1, sizeof(DP));

		hight[1] = n, hight[2] = n, hight[3] = n, hight[4] = n;

		for (int i = n; i > 0; --i)
		{
			for (int j = 1; j <= 4; ++j)
				cin >> plie[j][i];
		}

		cout << dfs(st, hight) << '\n';
	}

	return 0;
}
/*
5
1 2 3 4
1 5 6 7
2 3 3 3
4 9 8 6
8 7 2 1
1
1 2 3 4
3
1 2 3 4
5 6 7 8
1 2 3 4
0
*/