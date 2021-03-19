#pragma GCC optimize("O3")
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXQ = 100000;
int *arr, query[MAXQ], ans[MAXQ], buf[MAXQ]{};
int n, m, len, q;
int main()
{
    scanf("%d %d", &n, &m);
    arr = new int [len = n * m];
    for(int i = 0; i < len; i++)
        scanf("%d", arr + i);
    scanf("%d", &q);
    for(int i = 0; i < q; *(query + i) = *(ans + i), i++)
        scanf("%d", ans + i);
    sort(ans, ans + q);
    for(int i = 0, x = 0; i < len; x++, i++)
        if(ans[x = lower_bound(ans, ans + q, *(arr + i)) - ans] == *(arr + i)) buf[x] = i + 1;
    for(int i = 0, x; i < q; putchar('\n'), i++)
        if(buf[(x = lower_bound(ans, ans + q, *(query + i)) - ans)] != 0)
            printf("yes [%d, %d]", (buf[x] - 1) / m + 1, (buf[x] - 1) % m + 1);
        else putchar('n'),putchar('o');
    delete arr;
    return 0;
}
