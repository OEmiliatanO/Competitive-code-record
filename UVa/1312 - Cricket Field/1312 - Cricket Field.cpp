// 1312 - Cricket Field.cpp
#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <set>
#include <vector>
#include <cassert>
#include <fstream>

using namespace std;

using pii = pair<int, int>;
constexpr int MAXN = 110;

int t;
int n, w, h;

pii trees[MAXN + 1];
set<int> ypoints;
vector<int> v;

int main()
{
    cin >> t;
    while (t--)
    {
        ypoints.clear();
        v.clear();

        cin >> n >> w >> h;
        for (int i = 0; i < n; ++i)
        {
            cin >> trees[i].first >> trees[i].second;
            ypoints.emplace(trees[i].second);
        }

        ypoints.emplace(0); ypoints.emplace(h);

        trees[n].first = 0, trees[n].second = -1;
        trees[n + 1].first = w, trees[n + 1].second = -1;

        n += 2;

        sort(trees, trees + n);

        v.assign(ypoints.begin(), ypoints.end());
        
        int P = -1, Q = -1, L = -1;

        for (int i = 0; i < v.size(); ++i)
            for (int j = i + 1; j < v.size(); ++j)
            {
                int Lbondary = 0;
                for (int k = 1; k < n; ++k)
                {    
                    int nowL = v[j] - v[i];
                    assert(nowL > 0);

                    if ((trees[k].second < v[j] && trees[k].second > v[i]) or (trees[k].second == -1))
                    {
                        nowL = min(nowL, trees[k].first - Lbondary);
                        if (nowL > L)
                            L = nowL, P = Lbondary, Q = v[i];
                        Lbondary = trees[k].first;
                    }
                }
            }

        assert(L >= 0 && P >= 0 && Q >= 0);

        cout << P << ' ' << Q << ' ' << L << '\n';
        if (t) cout << '\n';
    }

    return 0;
}

/*
1

7 10 7
3 2
4 2
7 0
7 3
4 5
2 4
1 7

*/