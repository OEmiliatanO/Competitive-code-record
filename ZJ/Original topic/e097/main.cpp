#include <cstdio>
#include <cmath>

using namespace std;

typedef unsigned long long uint64;

const int SIZE = 32000;

int primes[SIZE], pointer, T, A, M, a, m, h, piPow_cnt, lim;
uint64 b, c;
bool notPrime[SIZE] = { true, true };

int main()
{
    for(int i = 2; i < SIZE; ++i)
    {
        if(!notPrime[i]) primes[pointer++] = i;
		for(int j = 0; i * primes[j] < SIZE; ++j)
		{
			notPrime[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}

	scanf("%d %d %d", &T, &A, &M);
	while (T-- && scanf("%d %d %d", &a, &m ,&h))
    {
        lim = sqrt(a);
        b = c = 1;
        for(int i = 0; primes[i] <= lim; ++i)
            if(a % primes[i] == 0)
            {
                piPow_cnt = 0;
                do
                {
                    a /= primes[i], ++piPow_cnt;
                }while(a % primes[i] == 0);

                piPow_cnt *= m;

                for(int j = piPow_cnt % h; j; --j)
                    c *= primes[i];

                piPow_cnt /= h;

                while(piPow_cnt--)
                    b *= primes[i];
            }

        if(a != 1)
        {
            piPow_cnt = m;
            for (int j = piPow_cnt % h; j; --j)
                c *= a;
            piPow_cnt /= h;
            while (piPow_cnt--)
                b *= a;
        }

        printf("%llu %llu\n", b, c);
    }
}
