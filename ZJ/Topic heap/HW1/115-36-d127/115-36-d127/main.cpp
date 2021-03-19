#include <iostream>

using namespace std;

int main()
{
    long int L;
    while(cin>>L)
    {
        L/=2;
        cout<<L*L/4<<endl;
    }
    return 0;
}
