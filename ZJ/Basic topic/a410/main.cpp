#include <cstdio>

using namespace std;

int main()
{
    for(double a,b,c,d,e,f,_;scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f)!=EOF;)
        if(a*e==b*d&&b*f==c*e) printf("Too many\n");
        else if(a*e==b*d&&b*f!=c*e) printf("No answer\n");
        else printf("x=%.2lf\ny=%.2lf\n",(c*e-f*b)/(a*e-b*d),(a*f-d*c)/(a*e-b*d));
    return 0;
}
