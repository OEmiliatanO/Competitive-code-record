#include <cstdio>

using namespace std;

int main()
{
    int h;
    scanf("%d",&h);
    h-=15;
    printf("%d",(h<0?h+24:h));
    return 0;
}
