#include <cstdio>
#include <cstring>
using namespace std;
int dir[10][4]={{0},{2,4},{1,3,5},{2,6},{1,5,7},{2,4,6,8},{3,5,9},{4,8},{5,7,9},{6,8}};
bool place[10];
int main()
{
    int n;scanf("%d",&n);
    bool ans=false;
    for(int a,b,c;n--&&scanf("%d %d %d",&a,&b,&c);ans=false)
    {
        memset(place,false,sizeof(place));
        for(int i=0;i<4&&dir[a][i]!=0;i++) place[dir[a][i]]=true;
        for(int i=0;i<4&&dir[b][i]!=0;i++) place[dir[b][i]]=false;
        for(int i=0;i<4&&dir[c][i]!=0;i++) place[dir[c][i]]=false;
        for(int i=1;i<=9;i++) if(place[i]) {printf("%d ",i); ans=true;}
        if(!ans) puts("Empty");
        else puts("");
    }
    return 0;
}
