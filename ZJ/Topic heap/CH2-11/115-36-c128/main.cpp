#include <string>
#include <iostream>
#include <map>
#include <cstring>
#define min(x,y) (x)>(y)?(y):(x)
#define max(x,y) (x)<(y)?(y):(x)
using namespace std;
map<string,int> roadnum;
int road[200][200],cnt=0;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    for(int n,r,t=1,start,End;cin>>n>>r&&(n|r);roadnum.clear(),t++,cnt=0)
    {
        memset(road,-1,sizeof(road));
        for(int i=0;i<n;i++) road[i][i]=0;
        cin.ignore();
        for(int i=0,a,b,wi;i<r;i++)
        {
            cin>>s;
            cin.ignore();
            if(roadnum.find(s)!=roadnum.end()) a=roadnum[s];
            else a=roadnum[s]=cnt++;
            cin>>s;
            cin.ignore();
            if(roadnum.find(s)!=roadnum.end()) b=roadnum[s];
            else b=roadnum[s]=cnt++;
            cin>>wi;
            road[b][a]=road[a][b]=wi;
        }
        cin>>s;
        cin.ignore();
        start=roadnum[s];
        cin>>s;
        End=roadnum[s];
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    road[i][j]=road[i][j]=max(road[i][j],min(road[i][k],road[k][j]));
        cout<<"Scenario #"<<t<<'\n'<<road[start][End]<<" tons"<<'\n'<<'\n';
    }
    return 0;
}
