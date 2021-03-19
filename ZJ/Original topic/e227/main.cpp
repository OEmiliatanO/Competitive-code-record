#include <cstdio>
#include <cmath>
#define abs(x) (~(x) + 1)
#define dist(x1, y1, x2, y2) sqrt(((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
using namespace std;

int d, p[2][4];

int main()
{
    for(int i = 0; i < 4 && scanf("%d %d", &p[0][i], &p[1][i]); ++i);

    d = dist(p[0][0], p[1][0], p[0][1], p[1][1]);

    if(dist(p[0][1], p[1][1], p[0][2], p[1][2]) != d || dist(p[0][2], p[1][2], p[0][3], p[1][3]) != d)
        puts("No!");
    else if(p[1][0] != p[1][1] || p[0][1] != p[0][2] || p[1][2] != p[1][3] || p[0][0] != p[0][3])
        puts("No!");
    else
        puts("Square!");
    return 0;
}
