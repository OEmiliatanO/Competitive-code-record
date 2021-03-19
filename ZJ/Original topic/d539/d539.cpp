#include <iostream>
#include <algorithm>
#include <cstdint>
#include <climits>

using namespace std;

constexpr int MAXN = 5e5;

int n;
int64_t arr[MAXN + 1];
int64_t seg[(MAXN + 1) << 2];

void build(int now = 1, int nl = 1, int nr = n)
{
	if (nl == nr)
	{
		seg[now] = arr[nl];

		return;
	}

	int mid = nl + nr >> 1;
	build(now << 1, nl, mid);
	build(now << 1 | 1, mid + 1, nr);
	seg[now] = max(seg[now << 1], seg[now << 1 | 1]);
}

int64_t query(int now, int nl, int nr, int ql, int qr)
{
	if (nl >= ql && nr <= qr)
	{
		return seg[now];
	}

	int mid = nl + nr >> 1;
	int64_t ans = INT64_MIN;
	if (mid >= ql)
		ans = max(query(now << 1, nl, mid, ql, qr), ans);
	if (mid < qr)
		ans = max(query(now << 1 | 1, mid + 1, nr, ql, qr), ans);
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	build();

	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);

		cout << query(1, 1, n, l, r) << '\n';
	}

	return 0;
}