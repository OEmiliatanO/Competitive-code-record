#include <cstdio>

using namespace std;

int X;

int main()
{
    scanf("%d", &X);
    X %= 5;
    switch(X)
    {
        case 0:
            putchar('U');
            break;
        case 1:
            putchar('G');
            break;
        case 2:
            putchar('Y');
            break;
        case 3:
            putchar('T');
            break;
        case 4:
            putchar('I');
            break;
    }
    return 0;
}
