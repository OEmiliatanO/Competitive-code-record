#include <cstdio>
#include <algorithm>

using namespace std;

const short ADD = 0, SUB = 1, MUL = 2;
bool pass;
int d[5];

int main()
{
    while(~scanf("%d %d %d %d %d", &d[0], &d[1], &d[2], &d[3], &d[4]) && (d[0] || d[1] || d[2] || d[3] || d[4]))
    {
        sort(d, d + 5);
        do
        {
            pass = false;
            for(int i = 0; i < 3 && !pass; ++i)
            {
                int sum = 0;

                if(i == ADD) sum = d[0] + d[1];
                else if(i == SUB) sum = d[0] - d[1];
                else if(i == MUL) sum = d[0] * d[1];

                for(int j = 0; j < 3 && !pass; ++j)
                {
                    int sum_ = sum;
                    if(j == ADD) sum_ += d[2];
                    else if(j == SUB) sum_ -= d[2];
                    else if(j == MUL) sum_ *= d[2];

                    for(int k = 0; k < 3 && !pass; ++k)
                    {
                        int sum__ = sum_;
                        if(k == ADD) sum__ += d[3];
                        else if(k == SUB) sum__ -= d[3];
                        else if(k == MUL) sum__ *= d[3];

                        for(int n = 0; n < 3 && !pass; ++n)
                        {
                            int sum___ = sum__;
                            if(n == ADD) sum___ += d[4];
                            else if(n == SUB) sum___ -= d[4];
                            else if(n == MUL) sum___ *= d[4];

                            if(sum___ == 23) pass = true;
                        }
                    }
                }
            }
        }while(next_permutation(d, d + 5) && !pass);

        if(pass) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
