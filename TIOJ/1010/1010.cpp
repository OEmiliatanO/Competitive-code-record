#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstring>
#define min(x, y) ((x) > (y) ? (y) : (x))
using namespace std;

constexpr int MAXN = 1001;

char p[MAXN], q[MAXN];
int f[MAXN], len1, len2, ans;

bool cmp(int len) noexcept
{
	for (int i = 0; i < len; ++i)
		if (p[i] != q[len2 - len + i])
			return false;

	return true;
}

int main() {
	scanf("%s", p);
	scanf("%s", q);
	
	len1 = strlen(p), len2 = strlen(q);
	
	for (int i = 0; i <= min(len1, len2); ++i)
		if (cmp(i))
			ans = i;

	printf("%d", ans);

	return 0;
}
