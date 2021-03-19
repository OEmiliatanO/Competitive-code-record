#include <cstdio>
#include <algorithm>
#define cardNum first
#define pos second

using namespace std;

const int MAXN = 1000000;
const bool toward = true, backward = false;

int n, nowPos = 1, ans = 0;
bool dir = toward;
pair<int, int> card[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; card[i].pos = i + 1, i++) scanf("%d", &card[i].cardNum);
    sort(card, card + n);
    for(int i = 0; i < n; nowPos = card[i].pos, i++)
    {
        if(nowPos <= card[i].pos)
            ans += (dir != toward), dir = toward;
        else
            ans += (dir != backward), dir = backward;
    }
    printf("%d",ans);
    return 0;
}
