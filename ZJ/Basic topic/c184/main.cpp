#include <cstdio>
using namespace std;
int n,tmp,tmp2;
int addTot(int a)
{
    int result=0;
    for(int i=1;i<a;i++)
        result+=(a%i==0?i:0);
    return result;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        tmp=addTot(n);
        tmp2=addTot(tmp);
        if(tmp==n) printf("=%d\n",n);
        else if(tmp2==n) printf("%d\n",tmp);
        else puts("0");
    }
    return 0;
}
