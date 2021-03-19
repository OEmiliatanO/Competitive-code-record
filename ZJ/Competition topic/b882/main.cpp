#include <cstdio>
using namespace std;
int main()
{
    unsigned int H,M,S;scanf("%u %u %u",&H,&M,&S);
    M+=S/60,S%=60,H+=M/60,M%=60,H%=24;
    printf("%02u:%02u:%02u",H,M,S);
    return 0;
}
