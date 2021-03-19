#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    for(int a,b,c;scanf("%d %d %d",&a,&b,&c)!=EOF;)
    {
        int Max=max(a,max(b,c)),Min=min(a,min(b,c));
        printf("%d %d %d\n",Min,a+b+c-Max-Min,Max);
        if(a+b+c-Max<=Max)
            printf("No\n");
        else
        {

            int _1=Min,_2=a+b+c-Max-Min,_3=Max;
            long long D=_1*_1+_2*_2,D3=_3*_3;
            if(D<D3)
                printf("Obtuse\n");
            else if(D==D3)
                printf("Right\n");
            else
                printf("Acute\n");
        }
    }
    return 0;
}
