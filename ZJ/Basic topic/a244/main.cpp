#include <cstdio>
using namespace std;

int main()
{
    int N,a,b,c;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d %d",&a,&b,&c);
        switch(a)
        {
            case 1:
                printf("%lld\n",(long)b+c);
                break;
            case 2:
                printf("%d\n",b-c);
                break;
            case 3:
                printf("%lld\n",(long)b*c);
                break;
            case 4:
                printf("%d\n",b/c);
                break;
        }
    }
    return 0;
}
