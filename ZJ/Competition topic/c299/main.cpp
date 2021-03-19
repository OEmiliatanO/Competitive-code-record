#include <cstdio>
#include <algorithm>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

using namespace std;

int n, tmp, min0, max0, in;

int main()
{
	while(~scanf("%d", &n))
	{
		tmp = n, min0 = 999999, max0 = -1;
		while(tmp-- && scanf("%d", &in))
		{
			max0 = max(max0, in);
			min0 = min(min0, in);
		}

		printf("%d %d ", min0, max0);

		if(max0 - min0 == n - 1) puts("yes");
		else puts("no");
        putchar('\n');
	}
	return 0;
}
