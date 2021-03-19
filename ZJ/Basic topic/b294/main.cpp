#include <cstdio>

using namespace std;

int main()
{
    for(int n;scanf("%d",&n)!=EOF&&n;)
    {
        int money=0;
        for(int i=1,m;i<=n&&scanf("%d",&m);i++)
            money+=(i*m);
        printf("%d\n",money);
    }
    return 0;
}
