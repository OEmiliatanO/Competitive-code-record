#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef gp_hash_table<int, bool> ht;

int n, m, l, index, x;

int main()
{
    while(~scanf("%d %d", &n, &m) && n && m)
    {
        scanf("%d", &l);
        while(l-- && scanf("%d:%d", &index, &x))
            ht[index] = (bool)x;
        scanf("%d", &l);
        while(l-- && scanf("%d:%d", &index, &x))
            if(ht.find(index).second == true)
                ht[index] &= x;
        for(auto it : ht)
            if(it.second)
            {

            }
    }
    return 0;
}
