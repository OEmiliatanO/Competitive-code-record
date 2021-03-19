#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char s[1001];
int cnt[1001][129];

int main()
{
	while (~scanf("%d %d", &n, &m) && getchar() && (n | m))
	{
		memset(cnt, 0, sizeof(int) * 1001 * 129);

		for (int i = 0; i < n * m - 1; ++i)
		{
			scanf("%[^\n]s", s);
			getchar();

			for (int j = 0; s[j]; ++j)
				++cnt[j][s[j]];
		}

		for (int i = 0; i < 1000; ++i)
			for (int j = 0; j < 128; ++j)
				if (cnt[i][j] % m)
				{
					putchar(j);
					break;
				}

		puts("");
	}

	return 0;
}
