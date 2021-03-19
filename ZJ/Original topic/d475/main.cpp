#include <cstdio>
#include <cmath>
using namespace std;
int a,n,t=0;
int _pow(const int &a,const int &b)
{
    if(a==1||a==0) return a;
    else if(a==-1) return (b&1?-1:1);
    else if(b==1) return a;
    else if(b==0) return 1;
    else if(a==2&&b>=1)
    {
        int res=1;
        for(int i=1;i<=b;res<<=1,i++);
        return res;
    }
    return pow(a,b);
}
int main()
{
    while(~scanf("%d %d",&a,&n)&&(a||n))
        printf("%d\n",_pow(a,n)),t++;
    puts("All Over. Exceeded 65536 lines!");
    return 0;
}
