#include <cstdio>

using namespace std;

int main()
{
    for(int n;scanf("%d",&n)!=EOF;)
        if(n<0) printf("%d\n",-1);
        else printf("%o\n",n);
    return 0;
}
