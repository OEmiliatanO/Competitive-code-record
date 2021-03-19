#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

gp_hash_table<short, short> Sign;
int N, M, x;

int main()
{
    scanf("%d %d", &N, &M);
    while(M-- && scanf("%d", &x))
        Sign[x]++;

    x = 0;
    for(int i = 1; i <= N; ++i)
        x += (Sign[i] < 2);

    printf("%d", x);

    return 0;
}
