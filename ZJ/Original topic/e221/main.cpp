#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const double EPS = 1e-8;
const int N = 14;
vector<int> ans;
double a, b, target;

bool dfs(double c, int now, int depth)
{
    if (fabs(c) < EPS)
        return true;
    if (depth <= 0)
        return false;

    for (int i = now; i <= 30; ++i)
        if(c - 1.0 / i >= -EPS && dfs(c - 1.0 / i, i, depth - 1))
        {
            ans.emplace_back(i);
            return true;
        }

    return false;
}

int main()
{
    scanf("%d %d", &a, &b);
    target = a / b;

    for (int depth = 1; depth <= 10; ++depth)
    {
        ans.clear();
        if(dfs(target, 1, depth))
        {
            printf("%d\n", ans.size());
            for ( int i = ans.size() - 1; i >= 0; --i )
                printf("%d\n", ans[i]);
            break;
        }
    }

    return 0;
}
