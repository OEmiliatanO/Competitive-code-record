#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64;

const int N = 40;
const int64 INF = 0x3fffffff;

int n, n2, W, m, w[N], v[N];
int64 _w, _v, tv, ans = 0;
pair <int64, int64> pack[1 << (N >> 1)];

int main()
{
    scanf("%d %d", &n, &W);

    for(int i = 0; i < n; ++i)
        scanf("%d %d", &v[i], &w[i]);

    n2 = n >> (m = 1);

    for(int i = 0; i < (1 << n2); ++i)
    {
        _w = _v = 0;
        for(int j = 0; j < n2; ++j)
            if((i >> j) & 1)
                _w += w[j], _v += v[j];
        pack[i] = make_pair(_w, _v);
    }

    sort(pack, pack + (1 << n2));

    for(int i = 1; i < (1 << n2); ++i)
        if(pack[m - 1].second < pack[i].second)
            pack[m++] = pack[i];

    for(int i = 0; i < (1 << (n - n2)); ++i)
    {
        _w = _v = 0;
        for(int j = 0; j < n - n2; ++j)
            if((i >> j) & 1)
                _w += w[n2 + j], _v += v[n2 + j];

        if(_w <= W)
        {
            tv = (lower_bound(pack, pack + m, make_pair(W - _w, INF)) - 1) -> second;
            ans = max(ans, _v + tv);
        }
    }
    printf("%lld", ans);
    return 0;
}
