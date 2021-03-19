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
    for(int y;scanf("%d",&y)!=EOF;)
        printf((Isleap(y)?"a leap year\n":"a normal year\n"));
    return 0;
}
