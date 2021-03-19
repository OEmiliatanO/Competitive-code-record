#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int a,b,c;scanf("%d %d %d",&a,&b,&c)!=EOF&&a&&b&&c;)
    {
        int sum=0;
        for(int i=1;i<=c;i++)
            if(!(i%a)) sum+=i;
            else if(!(i%b)) sum+=i;
        printf("%c\n",(sum>26?sum%26:sum)+'A'-1);
    }
    return 0;
}
