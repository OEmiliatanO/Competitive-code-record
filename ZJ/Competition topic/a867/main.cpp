#include <cstdio>
#define in(i,j) (((i)>=0&&(i)<15)&&((j)>=0&&(j)<30))
using namespace std;
int cnt;
char area[15][30],ch;
int main()
{
    while(~(ch=getchar()))
    {
        area[0][0]=ch;
        for(int j=1;j<30&&(ch=getchar());j++)area[0][j]=ch;
        for(int i=1;i<15&&getchar();i++)
            for(int j=0;j<30&&(ch=getchar());j++)
                area[i][j]=ch;
        for(int i=0;i<15;i++)
            for(int j=0;j<30;j++)
                if(area[i][j]=='.')
                {
                    cnt=0;
                    if(in(i-1,j-1)&&area[i-1][j-1]=='*') cnt++;
                    if(in(i-1,j)&&area[i-1][j]=='*') cnt++;
                    if(in(i-1,j+1)&&area[i-1][j+1]=='*') cnt++;
                    if(in(i,j-1)&&area[i][j-1]=='*') cnt++;
                    if(in(i,j+1)&&area[i][j+1]=='*') cnt++;
                    if(in(i+1,j-1)&&area[i+1][j-1]=='*') cnt++;
                    if(in(i+1,j)&&area[i+1][j]=='*') cnt++;
                    if(in(i+1,j+1)&&area[i+1][j+1]=='*') cnt++;
                    if(cnt>0) area[i][j]=cnt+'0';
                }
        for(int i=0;i<15;putchar('\n'),i++)
            for(int j=0;j<30;j++)
                putchar(area[i][j]);
        getchar();
    }
    return 0;
}
