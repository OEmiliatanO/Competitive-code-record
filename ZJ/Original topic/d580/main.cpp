#include <cstdio>

using namespace std;


int num[10001]{1, 1, 2};
int n;

int main()
{
    for(int i = 3; i <= 10000; i++)
        num[i] = (num[i - 1] + num[i - 2]) % 2012;
    while(~scanf("%d", &n))
        printf("%d\n", num[n]);
    return 0;
}
