#include <cstdio>
using namespace std;
typedef unsigned long long uint64;
uint64 summit[26][26]={};
int main()
{
    int n;
    for(int x=0;x<=25;x++)
        summit[0][x]=1;
    for(int y=1;y<=25;y++)
        for(int x=y;x<=25;x++)
            summit[y][x]=summit[y-1][x]+summit[y][x-1];
    while(scanf("%d",&n)!=EOF) printf("%llu\n",summit[n][n]);
    return 0;
}
