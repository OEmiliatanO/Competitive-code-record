#include <cstdio>
using namespace std;
bool Isleap(int Y)
{
    if((!(Y%4)&&(Y%100))||!(Y%400))
        return true;
    return false;
}
int main()
{
    int a,b,cnt=0;
    scanf("%d %d",&a,&b);
    for(int y=a;y<=b;y++) cnt+=Isleap(y);
    printf("%d",cnt);
    return 0;
}
