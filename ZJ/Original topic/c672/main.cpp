#include <cstdio>
#include <cstdlib>

using namespace std;

char s[13], out[5];
int pos, num;

int Convert(char ch)
{
    return (((ch >= '0' && ch <= '9') * (ch - '0')) + ((ch <= 'F' && ch >= 'A') * (ch - 'A' + 10)));
}

int scanf(int &i, int from)
{
    int res = 0, cnt = 0;
    while(s[i] && (s[i] > '9' || s[i] < '0') && (s[i] < 'A' || s[i] > 'F')) ++i;
    while(s[i] && ((s[i] <= '9' && s[i] >= '0') || (s[i] >= 'A' && s[i] <= 'F')))
    {
        ++cnt;
        res = res * from + Convert(s[i++]);
        if(from == 16 && cnt == 2) break;
    }
    return res;
}

int main()
{
    while(~scanf("%[^\n]s", s) && getchar())
    {
        pos = 0;
        if(s[0] == '#')
        {
            while(s[pos])
            {
                num = scanf(pos, 16);
                printf("%d ", num);
            }
        }
        else
        {
            putchar('#');
            while(s[pos])
            {
                num = scanf(pos, 10);
                printf("%02X", num);
            }
        }
        putchar('\n');
    }
    return 0;
}
