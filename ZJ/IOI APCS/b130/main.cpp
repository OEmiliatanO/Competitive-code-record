#include <cstdio>

using namespace std;

bool num[1001]{};
int n, x, tot = 0;

int main()
{
    scanf("%d", &n);
    while(n-- && scanf("%d", &x))
        num[x] = true;
    for(int i = 1; i <= 1000; i++)
        if(num[i]) tot++;
    printf("%d\n", tot);
    for(int i = 1; i <= 1000; i++)
        if(num[i]) printf("%d ", i);
    return 0;
}
