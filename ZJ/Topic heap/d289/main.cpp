#include <cstdio>
#include <cassert>
using namespace std;
int cent[]={1,13,33,43,139,169,1309,2597};
int taget[8001]{};
int I;
int main()
{
    taget[0]=1;
    for(int i=0;i<8;i++)
        for(int j=cent[i];j<=8000;j++)
            taget[j]+=taget[j-cent[i]];
    while(~scanf("%d",&I)) printf("%d\n",taget[I]);
    return 0;
}
