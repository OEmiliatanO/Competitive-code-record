#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long uint64;
const int MAXN=102;
int T,W,N;
uint64 DP[MAXN][MAXN];
bool Map[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    stringstream ss;
    string s;
    cin>>T;
    while(T--&&cin>>W>>N&&cin.ignore())
    {
        memset(DP,0,sizeof(DP));
        memset(Map,false,sizeof(Map));
        for(int i=1,x,use;i<=W&&getline(cin,s,'\n');ss.clear(),ss.str(""),i++)
        {
            ss.str(s);
            ss>>use;
            while(ss>>x)
                Map[use][x]=true;
        }
        if(!Map[W][N]) DP[1][1]=1;
        for(int i=1;i<=W;i++)
            for(int j=1;j<=N;j++)
            {
                if(Map[i][j]) continue;
                DP[i][j]+=DP[i-1][j]+DP[i][j-1];
            }
        cout<<DP[W][N]<<'\n'<<'\n';
    }
    return 0;
}
