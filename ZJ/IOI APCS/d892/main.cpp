#include <cstdio>
#include <set>
#include <queue>
using namespace std;
int N,M,word,qu_time=0;
set<int> IsInTmp;
queue<int> Tmp;
int main()
{
    scanf("%d %d",&M,&N);
    for(int i=0;i<N&&scanf("%d",&word);i++)
    {
        if(!IsInTmp.count(word))
        {
            qu_time++;
            IsInTmp.insert(word);
            Tmp.push(word);
            if(Tmp.size()>M)
                IsInTmp.erase(Tmp.front()),Tmp.pop();
        }
    }
    printf("%d",qu_time);
    return 0;
}
