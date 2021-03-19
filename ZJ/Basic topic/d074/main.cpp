#include <iostream>

using namespace std;

int main()
{
    int n,Max;
    cin>>n;
    while(n--)
    {
        int X;
        cin>>X;
        Max=(X>Max?X:Max);
    }
    cout<<Max<<endl;
    return 0;
}
