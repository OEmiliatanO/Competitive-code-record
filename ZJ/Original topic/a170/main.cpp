#include <cstdio>
using namespace std;
int main()
{
    int N;scanf("%d",&N);
    for(long a,b;N--&&scanf("%o %o",&a,&b);printf("%X\n",a+b));
    return 0;
}
