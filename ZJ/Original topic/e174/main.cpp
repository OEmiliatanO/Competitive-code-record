#include <cstdio>

using namespace std;

short n, O, X;
char ch;

int main()
{
    scanf("%hd", &n); getchar();
    while(n--)
    {
        for(short i = 0; i < 19; ++i, getchar())
            for(short j = 0; j < 19 && (ch = getchar()); ++j)
                O += (ch == 'O'), X += (ch == 'X');
        printf("O:%d\nX:%d\n",O, X);
        puts((O > X ? "Black win!!" : "White win!!"));
    }
    return 0;
}
