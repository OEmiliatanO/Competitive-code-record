// 1326C.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

using int64 = long long;

constexpr int MAXN = 2e5;
constexpr int MOD = 998244353;

int64 n, k;
vector<int64> S;
int64 ans = 1;

int main()
{
    cin >> n >> k;
    

    for (int i = 1, a; i <= n; ++i)
    {
        cin >> a;
        if (a >= n - k + 1)
            S.emplace_back(i);
    }

    sort(S.begin(), S.end());

    assert(S.size() == k);

    for (int i = S.size() - 1; i; --i)
    {
        ans = ans % MOD * ((S[i] - S[i - 1]) % MOD) % MOD;
        assert(ans >= 0);
    }

    cout << (n - k + 1 + n) * k / 2 << ' ';
    assert(ans >= 0);
    cout << ans % MOD;

    return 0;
}