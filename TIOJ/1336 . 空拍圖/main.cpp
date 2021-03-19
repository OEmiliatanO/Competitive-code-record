#include <cstdio>
#include <cstring>
using namespace std;
int n,m,green,none;
char M[150][150];
inline bool is_inside(int x,int y)
{
    return (x<m&&x>=0&&y<n&&y>=0);
}
void dfs(int i,int j,char x)
{
	if (M[i][j]==x)
    {
        M[i][j]=0;
        if(is_inside(i-1,j-1)) dfs(i-1,j-1,x);
        if(is_inside(i-1,j)) dfs(i-1,j,x);
        if(is_inside(i-1,j+1)) dfs(i-1,j+1,x);
        if(is_inside(i,j-1)) dfs(i,j-1,x);
        if(is_inside(i,j+1)) dfs(i,j+1,x);
        if(is_inside(i+1,j-1)) dfs(i+1,j-1,x);
        if(is_inside(i+1,j)) dfs(i+1,j,x);
        if(is_inside(i+1,j+1)) dfs(i+1,j+1,x);
	}
}
int main()
{
	scanf("%d %d",&n,&m);getchar();
	none=green=0;
    for(int i=0;i<m;getchar(),i++)for(int j=0;j<n&&scanf("%c",&M[i][j]);j++);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(M[i][j]=='-'||M[i][j]=='G')
            {
                if(M[i][j]=='-') none++;
                else if(M[i][j]=='G') green++;
                dfs(i,j,M[i][j]);
            }
	printf("%d %d\n",green,none);
	return 0;
}
