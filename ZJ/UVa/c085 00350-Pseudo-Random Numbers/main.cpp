#include <cstdio>
#include <map>

using namespace std;

int Z, I, M, L, T = 1, Count;
map<int, int> num;

int main()
{
    while(~scanf("%d %d %d %d", &Z, &I, &M, &L) && M)
    {
        Count = 1;
        num.clear();
        num.emplace(L, Count++);

        while(true)
        {
            L = (Z * L + I) % M;

            if(num.find(L) != num.end())
                break;

            num.emplace(L, Count++);
        }

        auto it = num.find(L);

        printf("Case %d: %d\n", T++, Count - (it -> second));
    }
    return 0;
}
