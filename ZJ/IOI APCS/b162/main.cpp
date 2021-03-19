#include <cstdio>
#include <map>

using namespace std;

int n, x;
map<int, int> num;

int main()
{
    scanf("%d", &n);
    while(n-- && scanf("%d", &x))
        num[x]++;
    for(auto it : num)
        printf("%d %d\n", it.first, it.second);
    return 0;
}
