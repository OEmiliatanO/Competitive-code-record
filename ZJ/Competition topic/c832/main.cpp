#include <cstdio>
using namespace std;
int Topic[6],A=-1,B=-2,C=-3;
bool ans=false;
void dfs(int i)
{
    if(A==B||B==C||A==C||ans)
        return;
    else if(i==3)
    {
        ans=true;
        return;
    }
    for(int l=i*2;ans==false&&l<=i*2+1;l++)
    {
        if(i==0) {A=Topic[l];dfs(i+1);}
        else if(i==1) {B=Topic[l];dfs(i+1);B=-2;}
        else if(i==2) {C=Topic[l];dfs(i+1);C=-3;}
    }
}
int main()
{
    int T,t=0;
    scanf("%d",&T);
    for(;T--&&scanf("%d %d %d %d %d %d",&Topic[0],&Topic[1],&Topic[2],&Topic[3],&Topic[4],&Topic[5])==6;A=-1,B=-2,C=-3)
    {
        ans=false;
        dfs(0);
        t++;
        printf((ans?"Yes\n":"No\n"));
    }
    return 0;
}
