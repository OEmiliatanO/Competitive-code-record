#include <cstdio>
#define abs(x) (x)<0.0?0-(x):(x)
using namespace std;
const double shift=1e-6;
int main()
{
    int n;
    double temp;
    scanf("%d",&n);
    for(int i=0,m,p;i<n&&scanf("%d %d",&m,&p);i++)
    {
        temp=(double)(p-m)/m*100;
        if(temp>=0.0) printf("%.2f%% ",abs(temp+shift));
        else printf("%.2f%% ",temp-shift);
        if(temp>=10.0||temp<=-7.0) printf("dispose\n");
        else printf("keep\n");
    }
    return 0;
}
