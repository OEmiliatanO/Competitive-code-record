#include <cstdio>
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;
enum {B=0,G,C};
char Way[6][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};
int choose[6][3]={{B,C,G},{B,G,C},{C,B,G},{C,G,B},{G,B,C},{G,C,B}},c;
int bin[3][3],ans;
int main()
{
    while(~scanf("%d %d %d %d %d %d %d %d %d",&bin[0][B],&bin[0][G],&bin[0][C],&bin[1][B],&bin[1][G],&bin[1][C],&bin[2][B],&bin[2][G],&bin[2][C]))
    {
        ans=0x7f7f7f7f;
        for(int i=5,tmp=0;i>=0;tmp=0,i--)
        {
            for(int j=0;j<3;j++)
                if(choose[i][j]==B) tmp+=bin[j][G]+bin[j][C];
                else if(choose[i][j]==C) tmp+=bin[j][G]+bin[j][B];
                else if(choose[i][j]==G) tmp+=bin[j][B]+bin[j][C];
            if(ans>=tmp) ans=tmp,c=i;
        }
        printf("%s %d\n",Way[c],ans);
    }
    return 0;
}
