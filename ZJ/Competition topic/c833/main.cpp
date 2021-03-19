#include <cstdio>
using namespace std;
char in;
bool x_[3000],y_[3000];
int main()
{
    for(int N,M,p=0;scanf("%d %d",&N,&M)!=EOF;)
    {
        for(int y=0;y<N&&scanf("%c",&in);y++)
            for(int x=0;x<M&&scanf("%c",&in);x++)
                if(in=='#') {x_[x]=y_[y]=true;}
        for(int y=0;y<N;y++)
        {
            for(int i=0;i<M;i++)
                putchar((y_[y]||x_[i]?'#':'X'));
            putchar('\n');
        }
    }
    return 0;
}
