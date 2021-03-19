#include <cstdio>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    for(int H1,M1,H2,M2,M3;N--&&scanf("%d %d %d %d %d",&H1,&M1,&H2,&M2,&M3)!=EOF;)
    {
        M1+=M3;
        if(M1>=60) H1++,M1-=60;
        if(H1>H2) printf("No\n");
        else if(M1>M2) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
