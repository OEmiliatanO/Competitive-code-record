#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, tmp = 0, arr[100001];
bool flag = false;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n && scanf("%d", arr + i); ++i);
    sort(arr, arr + n, [](int &a, int &b){ return a > b; });
    for(int i = 0; i < n; ++i)
    {
        tmp += arr[i];
        if(tmp >= m)
        {
            printf("%d\n", i + 1);
            flag = true;
            break;
        }
    }

    if(!flag) puts("OAQ");

    return 0;
}
