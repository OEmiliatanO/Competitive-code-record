#include <cstdio>

using namespace std;

const int MAXN = 201;
int arr[MAXN], n, a, b;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n && ~scanf("%d", &a); i++) arr[i] = a;
    scanf("%d", &n);
    while(n-- && ~scanf("%d %d", &a ,&b))
        printf("%d\n", arr[a] + arr[b]);
    return 0;
}
