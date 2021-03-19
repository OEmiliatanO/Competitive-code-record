#include <cstdio>

using namespace std;

int main()
{
    for(int a,b;scanf("%d %d",&a,&b)!=EOF;)
    {
        if(a>b)
        {
            int _=b;
            b=a;
            a=_;
        }
        if(b%2) b--;
        if(a%2) a++;
        printf("%d\n",(a+b)*((b-a)/2+1)/2);
    }
    return 0;
}
