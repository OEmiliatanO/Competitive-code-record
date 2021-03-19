#include <cstdio>
#include <set>

using namespace std;

int N, op, l, r;
set<int> P;

int main()
{
    scanf("%d", &N);
    while(N-- && scanf("%d", &op))
    {
        if(op == 1 && scanf("%d", &op))
            P.emplace(op);
        else
        {
            scanf("%d %d", &l, &r);
            auto li = P.lower_bound(l);
            auto ri = P.lower_bound(r);
            if(ri != P.end() && *ri == r)
                ++ri;
            P.erase(li, ri);
        }

        if(P.empty())
            putchar('0');
        else if(P.size() == 1)
            printf("1 %d", *P.begin());
        else
        {
            auto last = P.end();
            --last;
            printf("2 %d %d", *P.begin(), *last);
        }
        putchar('\n');
    }
    return 0;
}
