#include <cstdio>

using namespace std;

int item1, item2, item3, item4, sum;

int main()
{
    while(~scanf("%d %d %d %d", &item1, &item2, &item3, &item4))
    {
        sum = 0;
        sum += item4;
        sum += item3;
        if(item1 <= item3 * 27)
            item1 = 0;
        else
            item1 = item1 % (item3 * 27);
        if(item1)
        {
            sum += (item2 >> 3);
            item2 %= 8;
            int last = 64 - ((item2) << 3);
            if(last >= item1)
                sum += item1;
            else
            {
                item1 -= last;
                sum += (item1 >> 6) + ((item1 & 63) != 0);
            }
        }
        else
            sum += (item2 >> 3) + ((item2 & 7) != 0);
        printf("%d\n", sum);
    }
    return 0;
}
