#include <cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int main()
{
    int h, l, r, build[10001]={0}, maxr = 0;
    while(~scanf("%d %d %d", &l, &h, &r))
    {
        maxr = (maxr, r);
        for(int index = l; index < r; ++index)
            build[index] = max(h, build[index]);
    }

    if(build[0])
        printf("0 %d ", build[0]);

    for(int i = 1; i < maxr + 2; ++i)
    {
        if(build[i - 1] != build[i])
            printf("%d %d ", i, build[i]);
    }
    putchar('\n');

    return 0;
}
