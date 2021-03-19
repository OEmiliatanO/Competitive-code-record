#include <cstdio>
#define abs(x) ((x)>0?(x):~(x)+1)
using namespace std;
typedef long long int64;
const int MAXN=1000001;
int Cans[MAXN];
int64 allremovecnt=0;
int main()
{
    for(int A,B,C,temp,removecnt=0;scanf("%d %d %d",&A,&B,&C)!=EOF;allremovecnt=removecnt=0)
    {
        for(int i=0;i<A&&scanf("%d",&Cans[i]);i++);
        for(int i=0;i<A-1;i++)
        {
            temp=abs(Cans[i]-Cans[i+1]);
            if(temp>C)
            {
                removecnt=(temp-C)/B+((temp-C)%B?1:0);
                allremovecnt+=removecnt;
                if(Cans[i]>Cans[i+1]) Cans[i]-=removecnt*B;
                else Cans[i+1]-=removecnt*B;
            }
        }
        for(int i=A-1;i>=1;i--)
        {
            temp=abs(Cans[i]-Cans[i-1]);
            if(temp>C)
            {
                removecnt=(temp-C)/B+((temp-C)%B?1:0);
                allremovecnt+=removecnt;
                if(Cans[i]>Cans[i-1]) Cans[i]-=removecnt*B;
                else Cans[i-1]-=removecnt*B;
            }
        }
        printf("%lld\n",allremovecnt);
    }
    return 0;
}
