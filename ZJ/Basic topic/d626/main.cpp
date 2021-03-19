#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

char arr[MAXN][MAXN];
bool arr_b[MAXN][MAXN];
void dfs(int i,int j)
{
    if(i<MAXN&&j<MAXN&&i>=0&&j>=0&&arr[i][j]=='-'&&!arr_b[i][j])
    {
        arr[i][j]='+';
        arr_b[i][j]=true;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
    }
}
int main()
{
    int n,_i,_j;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    cin>>_i>>_j;
    memset(arr_b,0,sizeof(arr_b));
    dfs(_i,_j);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j];
        cout<<endl;
    }
    return 0;
}
