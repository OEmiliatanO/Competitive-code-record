#include <cstdio>

using namespace std;

int main()
{
    for(int s,d1,d2,d3;scanf("%d %d %d %d",&s,&d1,&d2,&d3)&&(s|d1|d2|d3);)
    {
        int sum=0;
        if(s>d1) sum+=s-d1; else sum+=40-d1+s;
        if(d1>d2) sum+=40-d1+d2; else sum+=d2-d1;
        if(d2>d3) sum+=d2-d3; else sum+=40-d3+d2;
        sum+=120;
        printf("%d\n",sum*9);
    }
    return 0;
}
