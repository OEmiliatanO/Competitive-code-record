#include <cstdio>
#include <cstring>

using namespace std;

int N, Army[4][10];
long long ans=0;

int main()
{
    while(~scanf("%d",&N))
    {
        memset(Army,0,sizeof(Army));

        for(int i = 0, in1, in2, in3, in4; i < N; i++)
        {
            scanf("%d %d %d %d", &in1, &in2, &in3, &in4);
            Army[in1][(in2 << 2) | (in3 << 1) | in4]++;
        }

        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                for(int k = 0; k < 8; k++)
                    if((i | j | k) == 7)
                        ans += Army[1][i] * Army[2][j] * Army[3][k];
        printf("%lld\n", ans);
    }
    return 0;
}
