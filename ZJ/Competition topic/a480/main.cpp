#include <cstdio>
#include <algorithm>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

using namespace std;

const int MAXN = 1000005, INF = 0x7f7f7f7f;

struct City
{
    int a, b;
}city[MAXN];

int x1, y1, x2, y2, n, ans;

bool cmp(const City &i, const City &j)
{
    return i.a < j.a;
}

int main()
{
    while(~scanf("%d %d", &x1, &y1))
    {
        ans = INF;
        scanf("%d %d", &x2, &y2);

        scanf("%d", &n);
        for(int i = 0, x, y; i < n && scanf("%d %d", &x, &y); i++)
        {
            city[i].a = (x - x1) * (x - x1) + (y - y1) * (y - y1);
            city[i].b = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        }

        sort(city, city + n, cmp);

        for(int i = n - 2; i >= 0; i--)
            city[i].b = max(city[i].b, city[i + 1].b);

        city[n].b = 0;
        for(int i = 0; i < n; i++)
            ans = min(ans, city[i].a + city[i + 1].b);

        printf("%d\n", min(ans, city[0].b));
    }

    return 0;
}
