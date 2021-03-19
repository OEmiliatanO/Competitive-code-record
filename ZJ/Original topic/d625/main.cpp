#include <cstdio>
using namespace std;
char place[101][101];
void bfs(int,int);
int main()
{
    int n;scanf("%d",&n);
    getchar();
    for(int i=0;i<n;getchar(),i++) for(int j=0;j<n&&scanf("%c",&place[i][j]);j++);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(place[i][j]!='*') bfs(i,j);
    for(int i=0;i<n;puts(""),i++) for(int j=0;j<n;j++) printf("%c",place[i][j]);
    return 0;
}
void bfs(int i,int j)
{
    int cnt=0;
    if(place[i-1][j-1]=='*') cnt++;
    if(place[i-1][j]=='*') cnt++;
    if(place[i-1][j+1]=='*') cnt++;

    if(place[i][j-1]=='*') cnt++;
    if(place[i][j+1]=='*') cnt++;

    if(place[i+1][j-1]=='*') cnt++;
    if(place[i+1][j]=='*') cnt++;
    if(place[i+1][j+1]=='*') cnt++;
    if(cnt!=0) place[i][j]=cnt+'0';
}
