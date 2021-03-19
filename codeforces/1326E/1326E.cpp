// 1326E.cpp
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 3e5;

int n;
int ans;
int pos[MAXN + 1];

int seg[MAXN * 4 + 1]{}, tag[MAXN * 4 + 1]{};
void updata(int l, int r, int qr, int val, int now = 1)
{
    if (r <= qr)
    {
        seg[now] += val, tag[now] += val;
        return;
    }

    int mid = (l + r) >> 1;
    seg[now] += val;
    seg[now << 1] += tag[now], seg[now << 1 | 1] += tag[now];
    tag[now << 1] += tag[now], tag[now << 1 | 1] += tag[now];
    tag[now] = 0;

    updata(l, mid, qr, val, now << 1);
    if (mid < qr) updata(mid + 1, r, qr, val, now << 1 | 1);

    seg[now] = max(seg[now << 1 | 1], seg[now << 1]);
}

int main()
{
    cin >> n;
    ans = n;

    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        pos[x] = i;
    }

    updata(1, n, pos[ans], 1);
    cout << ans << ' ';

    for (int i = 1, bomb; i < n; ++i)
    {
        cin >> bomb;
        updata(1, n, bomb, -1);

        while (seg[1] <= 0)
            updata(1, n, pos[--ans], 1);

        cout << ans << ' ';
    }

    return 0;
}
