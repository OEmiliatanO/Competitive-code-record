#include <cstdio>

using namespace std;

int main()
{
    int h,m;
    scanf("%d %d",&h,&m);
    h+=2;
    m+=30;
    if(m>=60)
    {
        h+=1;
        m-=60;
    }
    if(h>=24)
        h-=24;
    printf("%02d:%02d",h,m);
    return 0;
}
