#include <cstdio>

using namespace std;

int n, ans = 0;

bool f()
{
    return (ans += n--) && n && f();
}

int main()
{
    scanf("%d", &n);
    f();
    printf("%d", ans);
    return 0;
}
