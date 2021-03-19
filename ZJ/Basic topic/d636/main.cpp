#include <cstdio>

using namespace std;

int pow(int a,int b)
{
    if(b==1)
        return a;
    if(b%2)
    {
        long _=pow(a,(b-1)/2)%10007;
        return (_*_*a)%10007;
    }
    else
    {
        long _=pow(a,b/2)%10007;
        return (_*_)%10007;
    }
}

int main()
{
    for(int a,b;scanf("%d %d",&a,&b)!=EOF;)
    {
        a%=10007;
        if(b==0||a==1)
            printf("1\n");
        else
            printf("%d\n",pow(a,b));
    }
    return 0;
}
