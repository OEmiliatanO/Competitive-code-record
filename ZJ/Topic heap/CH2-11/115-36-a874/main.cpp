#include <cstdio>
#include <cstring>
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
using namespace std;
int way[26][26],N,T;
char X,Y;
int main()
{
    for(;scanf("%d",&N)!=EOF;)
    {
        memset(way,0x3f,sizeof(way));
        for(int i=0;i<26;i++) way[i][i]=0;
        getchar();
        for(int i=0;i<N&&scanf("%c %c %d",&X,&Y,&T);getchar(),i++)
            way[X-'A'][Y-'A']=way[Y-'A'][X-'A']=T;
        scanf("%c %c",&X,&Y);
        for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++)
                    way[j][i]=way[i][j]=min(way[i][j],way[i][k]+way[k][j]);
        if(way[X-'A'][Y-'A']>400000)
            printf("NoRoute\n");
        else
            printf("%d\n",way[X-'A'][Y-'A']);
    }
    return 0;
}
