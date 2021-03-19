#include <cstdio>
#include <string.h>
using namespace std;
bool chosen[50010];
int relation[50010],cnt;

void dfs(int person)
{
    if(chosen[person])
        cnt++;
    else
    {
        chosen[person]=true;
        dfs(relation[person]);
    }
}
int main()
{
    for(int n;scanf("%d",&n)!=EOF;)
    {
        memset(chosen,false,sizeof(chosen));
        cnt=0;
        for(int i=0;i<n&&scanf("%d",&relation[i]);i++);
        for(int i=0;i<n;i++)
            if(!chosen[i])
                dfs(i);
        printf("%d\n",cnt);
    }
    return 0;
}
