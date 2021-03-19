#include <cstdio>
using namespace std;
int Fib[45],p,N;
bool output=false;
int main()
{
    Fib[0]=Fib[1]=1;
    for(p=2;p<40;p++)
        Fib[p]=Fib[p-1]+Fib[p-2];
    scanf("%d",&N);
    for(int in;N--&&scanf("%d",&in)!=EOF;output=false)
    {
        printf("%d = ",in);
        for(int i=p-1;i>=1;i--)
        {
            if(Fib[i]<=in) {putchar('1'); in-=Fib[i]; output=true;}
            else if(output) putchar('0');
        }
        printf(" (fib)\n");
    }
    return 0;
}
