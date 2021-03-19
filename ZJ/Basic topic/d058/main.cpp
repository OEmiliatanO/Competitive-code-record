#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
        cout<<(n>0?1:(n==0?0:-1))<<endl;
    return 0;
}
