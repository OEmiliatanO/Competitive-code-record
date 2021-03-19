#include <cstdio>
#include <cstring>
using namespace std;
short _hash[26]{1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
short W[11][11],L[11][11];
short N,M,len,pi,pj;
char ch,s[10],dir;
int main()
{
    N=getchar()-'0';getchar();
    for(short i=1;i<=N;i++)
    {
        for(short j=1;j<=N;j++)
        {
            scanf("%s",s);
            if(s[0]!='[')
            {
                int t=s[0]-'0';
                if(s[1]=='W') W[i][j]=t;
                else L[i][j]=t;
            }
        }
    }
    scanf("%hd",&M);
    for(short i=0,scoor;i<M;i++)
    {
        scoor=0;
        scanf("%s %hd %hd %c",&s,&pi,&pj,&dir);
        len=strlen(s);
        short p_i=pi,p_j=pj;
        for(int j=0;j<len;j++)
        {
            scoor+=((L[p_i][p_j]?L[p_i][p_j]:1)*_hash[s[j]-'A']);
            if(dir=='V') p_i++;
            else p_j++;
        }
        p_i=pi,p_j=pj;
        for(int j=0;j<len;j++)
        {
            scoor*=(W[p_i][p_j]?W[p_i][p_j]:1);
            if(dir=='V') p_i++;
            else p_j++;
        }
        printf("%s %hd\n",s,scoor);
    }
    return 0;
}
