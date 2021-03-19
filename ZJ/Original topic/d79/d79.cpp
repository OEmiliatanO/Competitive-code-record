#include <iostream>

using namespace std;

constexpr int MAXN = 500000;

int64_t arr[MAXN + 1], lz[(MAXN + 1) << 2]{}, seg[(MAXN + 1) << 2]{};

void build(int now, int l, int r)
{
	if (l == r)
	{
		seg[now] = arr[l];
		return;
	}

	int mid = l + r >> 1;
	build(now << 1, l, mid);
	build(now << 1 | 1, mid + 1, r);

	seg[now] = seg[now << 1] + seg[now << 1 | 1];
}

void add(int now, int l, int r, int ql, int qr, int64_t k)
{
	if (ql <= l && qr >= r)
	{
		seg[now] += (1LL + r - l) * k;
		lz[now] += k;
		return;
	}

	int mid = l + r >> 1;

	if (lz[now])
	{
		seg[now << 1] += (1LL + mid - l) * lz[now], seg[now << 1 | 1] += (0LL + r - mid) * lz[now];
		lz[now << 1] += lz[now], lz[now << 1 | 1] += lz[now];
		lz[now] = 0;
	}

	if (mid >= ql)
		add(now << 1, l, mid, ql, qr, k);
	if (mid < qr)
		add(now << 1 | 1, mid + 1, r, ql, qr, k);

	seg[now] = seg[now << 1] + seg[now << 1 | 1];
}

int64_t query(int now, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
		return seg[now];

	int64_t res = 0;
	int mid = l + r >> 1;
	if (lz[now])
	{
		seg[now << 1] += (1LL + mid - l) * lz[now], seg[now << 1 | 1] += (0LL + r - mid) * lz[now];
		lz[now << 1] += lz[now], lz[now << 1 | 1] += lz[now];
		lz[now] = 0;
	}

	if (mid >= ql)
		res += query(now << 1, l, mid, ql, qr);
	if (mid < qr)
		res += query(now << 1 | 1, mid + 1, r, ql, qr);

	return res;
}

int main()
{
	int n, q, op, l, r;
	int64_t k;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	build(1, 1, n);

	cin >> q;
	while (q--)
	{
		cin >> op >> l >> r;
		if (op == 1)
		{
			cin >> k;
			add(1, 1, n, l, r, k);
		}
		else
			cout << query(1, 1, n, l, r) << '\n';
	}

	return 0;
}