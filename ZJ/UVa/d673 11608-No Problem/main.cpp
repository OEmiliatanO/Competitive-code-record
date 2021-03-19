#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int S, topic[12], need[12], t = 1;

int main()
{
    while(~scanf("%d", &S) && S >= 0)
    {
        for(int i = 0; i < 12; ++i)
            scanf("%d", topic + i);
        for(int i = 0; i < 12; ++i)
            scanf("%d", need + i);

        printf("Case %d:\n", t++);

        for(int i = 0; i < 12; S += topic[i], ++i)
            if(S < need[i])
                puts("No problem. :(");
            else
            {
                S -= need[i];
                puts("No problem! :D");
            }
    }
    return 0;
}
