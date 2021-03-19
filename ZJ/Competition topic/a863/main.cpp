#include <cstdio>
using namespace std;
int N;
void happy_N(int n)
{
    int tmp=0;
    for(int i=0;i<30&&n!=1;n=tmp,tmp=0,i++)
        while(n!=0) tmp+=(n%10)*(n%10),n/=10;
    if(n==1) printf("%d is a happy number\n",N);
    else printf("%d is an unhappy number\n",N);
}
int main()
{
    while(~scanf("%d",&N)) happy_N(N);
    return 0;
}
