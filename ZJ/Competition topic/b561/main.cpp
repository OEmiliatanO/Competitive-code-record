#include <cstdio>
#include <cmath>
using namespace std;
const double S=28.27431,M=63.6171975,L=113.09724,DL=201.06176,TL=314.159;
int n;
double first,second;
inline double getValue(int in)
{
    switch(in)
    {
    case 6:
        return S;
    case 9:
        return M;
    case 12:
        return L;
    case 16:
        return DL;
    case 20:
        return TL;
    }
    return 0;
}
int main()
{
    while(~scanf("%d",&n))
    {
        first=second=0;
        for(int i=0,in;i<n&&scanf("%d",&in);i++)
            first+=getValue(in);
        scanf("%d",&n);
        for(int i=0,in;i<n&&scanf("%d",&in);i++)
            second+=getValue(in);
        printf("%.2f\n",abs(first-second));
    }
    return 0;
}
