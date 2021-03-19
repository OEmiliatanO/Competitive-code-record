#include <cstdio>
#include <iostream>
using namespace std;
double U,H,D,F;
int last_day;
bool go()
{
    double nowhere=0;
    double f=U*F*0.01;
    while(true)
    {
        last_day++;
        nowhere+=U;
        if(nowhere>H)
            return true;
        nowhere-=D;
        if(nowhere<0)
            return false;
        U-=f;
        if(U<0) U=0;
    }
}

int main()
{
    for(;cin>>H>>U>>D>>F&&H!=0;)
    {
        last_day=0;
        if(go())
            printf("success on day %d\n",last_day);
        else
            printf("failure on day %d\n",last_day);
    }
    return 0;
}
