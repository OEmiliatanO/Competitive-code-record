#include <cstdio>
using namespace std;
double c,n;
int main()
{
    while(~scanf("%lf",&c))
    {
        n=0.0;
        int i=2;
        while(n<c)
            n+=((double)1/i),i++;
        printf("%d card(s)\n",i-2);
    }
    return 0;
}
