#include <cstdio>

using namespace std;

int T, ans;
char ch;

int main()
{
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        ans = 0;
        while((ch = getchar()) && ch != '\n')
            ans += (ch == 'X') * 2 + (ch == 'H') * 1;
        printf("%d\n", ans);
    }
    return 0;
}
