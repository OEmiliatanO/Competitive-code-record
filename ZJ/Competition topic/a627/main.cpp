#include <cstdio>
#include <cassert>
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;
int cap[4]={250,400,500,750};
int cost[4]={75,110,140,250};
int need,RAID,totCost,itemCnt,which,use;
int main()
{
    while(~scanf("%d %d",&need,&RAID))
    {
        totCost=0x7f7f7f7f;
        itemCnt=which=0;
        assert(RAID>=0&&RAID<=5);
        if(RAID==0)
        {
            for(int i=0;i<4;i++)
                for(int j=1;j<=8;j++)
                    if(cap[i]*j>=need)
                    {
                        if(totCost>cost[i]*j)
                        {
                            totCost=cost[i]*j;
                            itemCnt=j;
                            which=i;
                            use=j;
                        }
                    }
        }
        else if(RAID==1)
        {
            for(int i=0;i<4;i++)
                for(int j=1;j<=4;j++)
                    if(cap[i]*j>=need)
                    {
                        if(totCost>cost[i]*j*2)
                        {
                            totCost=cost[i]*j*2;
                            itemCnt=j*2;
                            which=i;
                            use=j;
                        }
                    }
        }
        else
        {
            for(int i=0;i<4;i++)
                for(int j=1;j<=7;j++)
                    if(cap[i]*j>=need)
                    {
                        if(totCost>cost[i]*(j+1))
                        {
                            totCost=cost[i]*(j+1);
                            itemCnt=(j+1);
                            which=i;
                            use=j;
                        }
                    }
        }
        printf("Qty: %d Disk: %dGB Price: $%d\n",itemCnt,cap[which],cost[which]);
        printf("Total price of this %dGB array: $%d\n",use*cap[which],totCost);
    }
    return 0;
}
