#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long int uint64;
uint64 N;
int main()
{
    while(~scanf("%llu",&N))
        printf("%.0f\n",pow(N,1/3.0));
    return 0;
}
