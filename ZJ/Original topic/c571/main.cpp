#include <cstdio>
#include <vector>
#include <algorithm>
#define lowBit(x) (x) & (~(x)+1)

using namespace std;

const int MAXN = 100000;
int n, ans[MAXN];
int bit[MAXN]{};

inline void add(int x, int addition)
{
    while(x < n)
    {
        bit[x] += addition;
        x += lowBit(x);
    }
}
inline int query(int x)
{
    int res = 0;
    while(x)
    {
        res += bit[x];
        x -= lowBit(x);
    }
    return res;
}

typedef struct point
{
    int y, z, id;
    point(){}
    point(int y, int z, int id):y(y), z(z), id(id) {}
}pt;
vector<vector<pt> > vec;

void D_C(int l, int r)
{
    if(r - l == 1) return;

    int mid = (l + r) >> 1;
    D_C(l, mid); D_C(mid, r);

    vector<pt> lp, rp;
    for(int i = l; i < mid; i++)
        for(auto tmp : vec[i])
            lp.emplace_back(tmp);
    for(int i = mid; i < r; i++)
        for(auto tmp : vec[i])
            rp.emplace_back(tmp);

    sort(lp.begin(), lp.end(), [](const pt &a, const pt &b){return a.y < b.y;});
    sort(rp.begin(), rp.end(), [](const pt &a, const pt &b){return a.y < b.y;});

    int index = 0;
    for(auto tmp : rp)
    {
        while(index < lp.size() && tmp.y > lp[index].y)
            add(lp[index++].z, 1);
        ans[tmp.id] += query(tmp.z - 1);
    }
    for(int i = 0; i < index; i++)
        add(lp[i].z, -1);
}
int main()
{
    scanf("%d", &n);
    vec.resize(n);

    for(int i = 0, x, y, z; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        vec[n - x].emplace_back(n - y + 1, n - z + 1, i);
    }

    D_C(0, n);
    for(int i = 0; i < n; putchar('\n'), i++)
        printf("%d", ans[i]);

    return 0;
}
