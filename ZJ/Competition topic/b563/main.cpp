#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n, A[100], B[100], ans;
bool used[100];

int main()
{
    while(~scanf("%d", &n))
    {
        ans = 0;

        for(int i = 0; i < n; used[i] = false, ++i)
            scanf("%d %d", A + i, B + i);

        for(int i = 0; i < n; ++i)
        {
            if(used[i]) continue;
            for(int j = i + 1; j < n; ++j)
            {
                if(A[i] == B[j] && A[j] == B[i] && !used[j])
                {
                    ++ans;
                    used[i] = used[j] = true;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
