#include <cstdio>
using namespace std;
int main()
{
    int a,b;
    char sy;
    for(;scanf("%d %c %d",&a,&sy,&b)!=EOF;)
        if(sy=='+') printf("%d\n",a+b);
        else if(sy=='-') printf("%d\n",a-b);
        else if(sy=='*') printf("%d\n",a*b);
        else printf("%d\n",a/b);
    return 0;
}
