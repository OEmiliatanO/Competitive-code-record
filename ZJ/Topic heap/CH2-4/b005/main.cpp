#include <cstdio>

using namespace std;
bool Matrix[100][100];
int main()
{
    for(int n,in,i_odd=0,j_odd=0,fix_i,fix_j;scanf("%d",&n)!=EOF;i_odd=0,j_odd=0)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n&&scanf("%d",&in);j++) Matrix[i][j]=(in==1?true:false);
        for(int i=0,cnt=0;i<n;i++,cnt=0)
        {
            for(int j=0;j<n;cnt+=(Matrix[i][j]?1:0),j++);
            if(cnt&1) {i_odd++; fix_i=i;}
        }
        for(int j=0,cnt=0;j<n;j++,cnt=0)
        {
            for(int i=0;i<n;cnt+=(Matrix[i][j]?1:0),i++);
            if(cnt&1) {j_odd++; fix_j=j;}
        }
        if(j_odd==1&&i_odd==1)
            printf("Change bit (%d,%d)\n",fix_i+1,fix_j+1);
        else if(j_odd==0&&i_odd==0)
            printf("OK\n");
        else
            printf("Corrupt\n");
    }
    return 0;
}
