#pragma warning( disable : 4996 )
#include <cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int n, k, maxlen = 1, len = 1;
char ch, lch = 0;

int main()
{
	scanf("%d %d", &n, &k); getchar();
	ch = getchar();
	for (int i = 1; i < n; ++i)
	{
		lch = ch;
		ch = getchar();
		if (ch != lch)
		{
			maxlen = max(maxlen, len);
			len = 1;
		}
		else
		{
			++len;
		}
	}

	if (maxlen + k > n)
		printf("%d", n);
	else
		printf("%d", maxlen + k);

	return 0;
}
