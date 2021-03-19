#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(double a,b,c,d;n--&&scanf("%lf %lf %lf %lf",&a,&b,&c,&d)!=EOF;)
    {
        if(b==0.0&&d==0.0)
            putchar((a>c?'>':(a<c?'<':'=')));
        else printf("No");
        putchar('\n');
    }
    return 0;
}
