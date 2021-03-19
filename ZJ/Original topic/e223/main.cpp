#include <cstdio>
#include <set>

using namespace std;

short N, M, a, b, K, tmp, person[1001];
set<short> P;
void swap(short &l, short &r)
{
    tmp = l;
    l = r;
    r = tmp;
}

int main()
{
    scanf("%hd", &N);
    for(int i = 1; i <= N; ++i) P.emplace(i), person[i] = i;

    scanf("%hd", &M);
    for(int i = 0; i < M && scanf("%hd %hd", &a, &b); ++i)
        swap(person[a], person[b]);

    scanf("%hd", &K);
    for(int i = 0; i < K && scanf("%hd", &tmp); ++i)
        for(int i = 1; i <= N; ++i)
            if(person[i] == tmp)
                P.erase(i);

    if(P.size())
        for(auto it : P)
            printf("%hd ", it);
    else puts("-1");
    return 0;
}
