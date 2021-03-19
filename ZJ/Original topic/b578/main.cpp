#include <iostream>
#include <algorithm>
using namespace std;
typedef long double double64;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    for(double64 a,b,c;T--&&cin>>a>>b>>c;)
    {
        double64 Max=max(a,max(b,c)),Min=min(a,min(b,c));
        double64 _1=Min,_2=a+b+c-Max-Min,_3=Max;
        double64 D=_1*_1+_2*_2,D3=_3*_3;
        if(D<D3)
            cout<<"obtuse triangle"<<'\n';
        else if(D==D3)
            cout<<"right triangle"<<'\n';
        else
            cout<<"acute triangle"<<'\n';
    }
    return 0;
}
