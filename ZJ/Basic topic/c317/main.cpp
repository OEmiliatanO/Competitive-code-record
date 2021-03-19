#include <cstdio>
using namespace std;
int X,a,b,N,a_c,b_c;
int main()
{
    scanf("%d",&N);
    while(N--&&scanf("%d %d %d",&X,&a,&b))
    {
        a_c=X/a;
        for(b_c=0;a_c>=0;)
        {
            if(a_c*a+b_c*b>X) a_c--;
            else if(a_c*a+b_c*b==X) break;
            else b_c++;
        }
        if(a_c*a+b_c*b==X) printf("%d\n",a_c+b_c);
        else puts("-1");
    }
    return 0;
}
