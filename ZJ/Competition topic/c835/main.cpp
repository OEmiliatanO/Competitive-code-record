#pragma GCC optimize("O3")
#include <cstdio>
#include <queue>
#include <cassert>

using namespace std;

typedef long long int64;

struct node
{
    int poww;
    int64 val;
};
struct cmp
{
    bool operator() (const node &lhs, const node &rhs)
    {
        return (lhs.poww > rhs.poww) || (lhs.poww == rhs.poww && lhs.val < rhs.val);
    }
};

typedef std::priority_queue<node, vector<node>, cmp> heap;
int N, M, sum;
node tmp;
heap pq;

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N && scanf("%d %lld", &tmp.poww, &tmp.val); ++i)
        if(tmp.poww > M) continue;
        else pq.emplace(move(tmp));

    tmp.poww = M, tmp.val = 0;

    while(pq.size() > 1)
    {
        tmp = pq.top(); pq.pop();
        if(tmp.poww == M) break;

        if(tmp.poww == pq.top().poww)
        {
            tmp.val += pq.top().val;
            ++tmp.poww;
            pq.pop();
        }
        else tmp.poww = pq.top().poww;

        pq.emplace(move(tmp));
    }

    printf("%lld", tmp.val);
    return 0;
}
