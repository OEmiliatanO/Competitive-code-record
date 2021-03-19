#include <bits/stdc++.h>
#define NotAnnoence 0
using namespace std;

int F[21]{0};

void comput(int N)
{
    if(N>=1&&N<=4)return;
    if(F[N-1]==NotAnnoence)
        comput(N-1);
    if(F[N-4]==NotAnnoence)
        comput(N-4);
    F[N]=F[N-4]+F[N-1];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        memset(F,0,sizeof(F));
        scanf("%d%d%d%d%d",&N,F+1,F+2,F+3,F+4);
        comput(N);
        /*for(int i=1;i<21;i++)
            printf("%d ",F[i]);
        printf("\n");*/
        sort(F+1,F+1+N);
        for(int i=1;i<21;i++)
            printf("%d ",F[i]);
        printf("\nans:");
        printf("%d",F[(N+1)/2]);
        printf("\n");
    }
    return 0;
}
