#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, m, x;
int pq[40000], index = 0;

int main()
{
    scanf("%d", &T);

    for(int kase = 1; kase <= T; ++kase)
    {
        scanf("%d %d", &n, &m);
        printf("Case %d:\n", kase);

        while(n-- && scanf("%d", &pq[index++]));
        make_heap(pq, pq + index);

        while(m-- && scanf("%d", &x))
        {
            if(x == 1)
            {
                scanf("%d", &pq[index++]);
                push_heap(pq, pq + index);
            }
            else
            {
                if(index)
                {
                    printf("Max: %d\n", pq[0]);
                    pop_heap(pq, pq + index--);
                }
                else
                    puts("It's empty!");
            }
        }
        if(index)
            while(index)
            {
                printf("%d ", pq[0]);
                pop_heap(pq, pq + index--);
            }
        else
            printf("It's empty!");
        putchar('\n');
    }
    return 0;
}
