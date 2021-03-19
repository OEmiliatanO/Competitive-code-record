#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    for(int N,M;scanf("%d %d",&N,&M)!=EOF;)
        printf("%d\n",(int)(M*log10(N)+1));
    return 0;
}
