#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int64;

int64 sum1 = 0, sum2 = 0;
int T, n, s, u, ps = 0;
double avg, sig = 0.0;

int main()
{
    scanf("%d", &T);
    while(T-- && scanf("%d %d %d", &n, &u, &s))
    {
        sum2 += (s * s + u * u) * n;
        sum1 += u * n;
        ps += n;
    }

    avg = (double)sum1 / ps;
    sig = sqrt((double)sum2 / ps - avg * avg);

    printf("%d %.2f %.2f", ps, avg, sig);

    return 0;
}
