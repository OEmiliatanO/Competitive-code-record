// 3523 test data creator.cpp
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

constexpr int MAXN = 1000;

fstream OUT;

bool connected[MAXN + 1][MAXN + 1];

int main()
{
    srand(923);

    OUT.open("00.in.txt", ios::out);

    for (int t = 0; t < 10; ++t)
    {
        memset(connected, false, sizeof(bool) * (MAXN + 1) * (MAXN + 1));

        int n = 300, m = 45000;

        OUT << n << ' ' << m << '\n';

        int cnt = 0;
        while (cnt < m)
        {
            int i = rand() % n + 1, j = rand() % n + 1;
            if (!connected[i][j])
            {
                OUT << i << ' ' << j << '\n';
                connected[i][j] = connected[j][i] = true;
                cnt++;
            }
        }
    }

    OUT << "0 0" << '\n';

    OUT.flush();
    return 0;
}
