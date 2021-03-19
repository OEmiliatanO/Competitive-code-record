#include <cstdio>
#include <cassert>
using namespace std;
double x[11],y[11],ans;
int N;
int main()
{
    while(~scanf("%d",&N))
    {
        ans=0;
        assert(N>=3&&N<=10);
        for(int i=0;i<N&&scanf("%lf %lf",&x[i],&y[i]);i++);
        for(int i=0;i<N;i++)
            ans+=x[i]*y[(i+1)%N]-x[(i+1)%N]*y[i];
        printf("%.2f\n",(ans<0.0?-ans/2:ans/2));
    }
    return 0;
}
