#include <cstdio>
using namespace std;
short n;
int cnt[6],sum=0,base=0;
int main()
{
    while(~scanf("%hd",&n)&&n)
    {
        cnt[n]++;
        sum+=n;
        base++;
    }
    for(int i=5;i>=1;i--)
    {
        printf("%d (%2d) |",i,cnt[i]);
        for(int j=0;j<cnt[i];j++)
            putchar('=');
        putchar('\n');
    }
    printf("Average rating: %.4f",(double)sum/base);
    return 0;
}
