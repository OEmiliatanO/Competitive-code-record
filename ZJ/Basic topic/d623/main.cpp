#include <cstdio>

using namespace std;
double a,b,c,d,det;
int main()
{
    for(;scanf("%lf %lf\n%lf %lf",&a,&b,&c,&d)==4&&a!=0&&b!=0&&c!=0&&d!=0;)
    {
        det=a*d-b*c;
        if(det) printf("%.5f %.5f\n%.5f %.5f\n",d/det,(-b)/det,(-c)/det,a/det);
        else printf("cheat!\n");
    }
    return 0;
}
