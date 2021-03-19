#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000001;
bool selfNumber[MAXN];

int process(int n)
{
    int sum = n;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    memset(selfNumber, true, MAXN);
    selfNumber[0] = false, selfNumber[1] = true;
    for(int i = 1; i < MAXN; ++i)
    {
        if(selfNumber[i])
            printf("%d\n", i);
        selfNumber[process(i)] = false;
    }
    return 0;
}
