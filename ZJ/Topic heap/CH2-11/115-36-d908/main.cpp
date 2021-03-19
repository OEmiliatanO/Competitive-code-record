#include <cstdio>
#include <string.h>
#define min(x,y) (x)>(y)?(y):(x)
#define abs(n) (n)<0?0-(n):(n)
using namespace std;
const int INF=1e9+1;
int Graph[26][26],start,n,minx=INF;
int main()
{
    for(char a,b;scanf("%c",&a)!=EOF;minx=INF)
    {
        bool input=false;
        memset(Graph,INF,sizeof(Graph));
        for(int i=0;i<26;i++) Graph[i][i]=0;
        start=a-'A';
        getchar();
        scanf("%d",&n);
        getchar();
        for(int i=0,wi;i<n&&scanf("%c %c %d",&a,&b,&wi);getchar(),i++)
            if(a-'A'>=0&&a-'A'<26&&b-'A'>=0&&b-'A'<26&&0-wi<Graph[a-'A'][b-'A'])
            {
                input=true;
                Graph[a-'A'][b-'A']=0-wi;
            }
        for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++)
                    Graph[i][j]=min(Graph[i][j],Graph[i][k]+Graph[k][j]);
        for(int i=0;i<26;i++)
            minx=min(minx,Graph[start][i]);
        if(input&&minx<0) printf("%d\n",abs(minx));
    }
    return 0;
}
