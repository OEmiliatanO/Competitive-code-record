#include <cstdio>
#include <vector>

using namespace std;

typedef short int16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

vector<pii> vec;
int n, len, num;

int main()
{
    for(int i = 1; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            if(i != j)
                vec.emplace_back(make_pair(i, j));

    while(~scanf("%d", &n))
    {
        n -= 1;
        len = n / vec.size() + 3;
        num = n % vec.size();

        for(int i = 0; i < (len >> 1); ++i)
        {
            putchar('0' + vec[num].first);
            putchar('0' + vec[num].second);
        }
        if(len & 1)
            putchar('0' + vec[num].first);

        putchar('\n');
    }

    return 0;
}
