#include <cstdio>

using namespace std;

int n, r, g, b;
double x, y, z, ys;

int main()
{
    while(~scanf("%d", &n))
    {
        ys = 0.0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                scanf("%d %d %d", &r, &g, &b);
                x = 0.5149 * r + 0.3244 * g + 0.1607 * b;
                y = 0.2654 * r + 0.6704 * g + 0.0642 * b;
                z = 0.0248 * r + 0.1248 * g + 0.8504 * b;
                ys += y;
                printf("%.4f %.4f %.4f\n", x, y, z);
            }
        printf("The average of Y is %.4f\n", ys / (n * n));
    }

    return 0;
}
