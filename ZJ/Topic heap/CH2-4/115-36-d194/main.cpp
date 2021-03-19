#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Case;
    long long n;
    for(scanf("%d",&Case);Case;Case--)
    {
        scanf("%lld",&n);
        queue<long long> Qu;
        set<long long> Num;
        int Max_Length=0;
        for(long long int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(Num.count(x))
            {
                while(Qu.front()!=x)
                {
                    Num.erase(Qu.front());
                    Qu.pop();
                }
                Qu.pop();
                Qu.push(x);
            }
            else
            {
                Num.insert(x);
                Qu.push(x);
            }
            Max_Length=(Max_Length<Qu.size()?Qu.size():Max_Length);
        }
        printf("%d\n",Max_Length);
    }
    return 0;
}
