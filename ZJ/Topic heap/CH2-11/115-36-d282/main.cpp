#include <iostream>
#include <string>
#include <cstring>
#define min(x,y) (x)<(y)?(x):(y)
#define INF 0x3f
using namespace std;
int n,m;
string group[23];
int Map[23][23];
int main()
{
    for(int kase=1,ans=0;cin>>n>>m&&n;kase++,ans=0)
    {
        cin.ignore();
        memset(Map,INF,sizeof(Map));
        for(int i=1;i<=n;i++) Map[i][i]=0;
        for(int i=1;i<=n&&getline(cin,group[i],'\n');i++);
        for(int t=0,i,j,k;t<m&&cin>>i>>j>>k;Map[i][j]=k,Map[j][i]=k,t++);
        for(int k=1;k<=n;k++)
            for(int j=1;j<=n;j++)
                for(int i=1;i<=n;i++)
                {
                    Map[i][j]=min(Map[i][j],Map[i][k]+Map[k][j]);
                    Map[j][i]=min(Map[i][j],Map[i][k]+Map[k][j]);
                }
        for(int select=1,sum=0,minx=0x3f3f3f;select<=n;sum=0,select++)
        {
            for(int i=1;i<=n;i++)
                sum+=Map[select][i];
            if(minx>sum) {ans=select; minx=min(minx,sum);}
        }
        cout<<"Case #"<<kase<<" : "<<group[ans]<<'\n';
    }
    return 0;
}
