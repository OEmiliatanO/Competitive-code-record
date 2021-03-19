#include <cstdio>

using namespace std;

int main()
{
    int N,T=0;
    scanf("%d",&N);
    for(int M;N--&&scanf("%d",&M);)
    {
        int S[M],average=0,Min=1000000;
        for(int i=0,m,s;i<M&&scanf("%d %d",&m,&s);S[i]=s+m*60,average+=S[i],Min=(Min>S[i]?S[i]:Min),i++);
        average/=M;
        printf("Track %d:\n",++T);
        printf("Best Lap: %d minute(s) %d second(s).\n",Min/60,Min%60);
        printf("Average: %d minute(s) %d second(s).\n",average/60,average%60);
    }
    return 0;
}
