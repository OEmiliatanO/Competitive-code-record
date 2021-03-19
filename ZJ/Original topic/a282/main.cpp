#include <cstdio>
#include <cstring>

using namespace std;

bool read[2001]{};
int n, r;

int main()
{
    while(~scanf("%d", &n))
    {
        memset(read, false, 2001);
        while(n-- && scanf("%d", &r))
            read[r] = true;
        for(r = 1; read[r]; r++);
        if(r != 2001) printf("%d\n", r);
    }
    return 0;
}
