#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<(n>25?(60-n+25):25-n)<<endl;
    }
    return 0;
}
