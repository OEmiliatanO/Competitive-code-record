#include <cstdio>
using namespace std;
typedef long long int64;
const int MAXN = 501;
int64 N,res,matrix[3][MAXN][MAXN];
bool isOk;
int main()
{
    while(~scanf("%d",&N))
    {
        isOk=true;
        for(int index=0;index<3;index++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    scanf("%lld",&matrix[index][i][j]);
        for(int i=0;i<N&&isOk;i++)
            for(int j=0;j<N&&isOk;j++)
            {
                res=0;
                for(int indexA=0,indexB=0;indexA<N;indexA++,indexB++)
                    res+=matrix[0][i][indexA]*matrix[1][indexB][j];
                if(res!=matrix[2][i][j]) isOk=false;
            }
        if(isOk) puts("YES");
        else puts("NO");
    }
    return 0;
}
