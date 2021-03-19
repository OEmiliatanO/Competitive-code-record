#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    for(double N;scanf("%lf",&N)!=EOF;)
        printf("|%.4f|=%.4f\n",N,abs(N));
    return 0;
}
