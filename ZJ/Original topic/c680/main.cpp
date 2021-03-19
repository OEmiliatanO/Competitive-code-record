#include <cstdio>
using namespace std;
char ans[101],stu[101];
int score,add;
int T,N;
int main()
{
    scanf("%d",&T);getchar();
    add=100/T;
    scanf("%[^\n]s",ans);
    scanf("%d",&N);getchar();
    while(N--&&scanf("%[^\n]s",stu)&&getchar())
    {
        score=0;
        for(int i=0;ans[i];i++)
            if(stu[i]==ans[i])
                score+=add;
        printf("%d\n",score);
    }
    return 0;
}
