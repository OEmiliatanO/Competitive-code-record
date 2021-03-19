#include <iostream>

using namespace std;

auto lowbit = [](auto i) { return i & (-i); };

constexpr int MAXN = 200010;

int64_t BIT[MAXN]{};

void modify(int pos, int64_t k)
{
    for (; pos < MAXN; pos += lowbit(pos))
        BIT[pos] += k;
}

int64_t query(int pos)
{
    int64_t res = 0;
    for (; pos; pos -= lowbit(pos))
        res += BIT[pos];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int64_t x;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        modify(i, x);
    }

    cin >> n;
    int l, r;
    while (n--)
    {
        cin >> l >> r;
        cout << query(r) - query(l - 1) << '\n';
    }
    return 0;
}
