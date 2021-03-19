#include <cstdio>
#include <cstring>
#include <cassert>
#include <set>
using namespace std;
int Cache[1025]{},hit=0,times=0;
bool eof;
set<int> used;
int main()
{
    while(true)
    {
        eof=true;
        for(int n,tmp=times;times<20+tmp&&~scanf("%d",&n);times++)
        {
            eof=false;
            for(auto item : used)
                Cache[item]++;
            if(used.count(n))
            {
                hit++;
                Cache[n]=1;
            }
            else
            {
                if(used.size()==16)
                {
                    int toErase=-1,tmpMax=-1;
                    for(auto item : used)
                        if(Cache[item]>tmpMax)
                            toErase=item,tmpMax=Cache[item];
                    used.erase(toErase);
                }
                Cache[n]=1;
                used.emplace(n);
            }
        }
        if(eof) break;
        printf("cache hit rate: %.2f%\n",(double)hit*100/times);
    }
    return 0;
}
