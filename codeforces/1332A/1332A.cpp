// 1332A.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

using int64 = long long;

constexpr int MAXN = 2e5;

int t;
int n, k;
string St;
string s[MAXN + 1];
int M[257];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        
        memset(M, 0, sizeof(int) * 257);

        cin >> St;
        for (int i = 0; i < n / k; ++i)
            s[i] = St.substr(i * k, k);

        int l = 0, r = k - 1;
        int cost = 0;
        while (l < r)
        {
            M[0] = 0;
            memset(M, 0, sizeof(int) * 257);
            for (int i = 0; i < n / k; ++i)
            {
                ++M[s[i][l]], ++M[s[i][r]];
                M[0] = max({ M[0], M[s[i][l]], M[s[i][r]] });
            }
            cost += n / k * 2 - M[0];

            ++l, --r;
        }

        if (l == r)
        {
            M[0] = 0;
            memset(M, 0, sizeof(int) * 257);
            for (int i = 0; i < n / k; ++i)
            {
                ++M[s[i][l]];
                M[0] = max(M[0], M[s[i][l]]);
            }
            cost += n / k - M[0];
        }

        cout << cost << '\n';
    }

    return 0;
}
