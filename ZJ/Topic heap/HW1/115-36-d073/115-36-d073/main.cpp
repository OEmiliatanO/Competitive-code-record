#include <iostream>

using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        cout<<((n%3==0)?(n/3):(n/3+1))<<endl;
    }
    return 0;
}
