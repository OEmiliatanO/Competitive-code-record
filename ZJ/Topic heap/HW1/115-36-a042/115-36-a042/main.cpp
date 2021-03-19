#include <iostream>

using namespace std;

int main()
{
    int n,_=2;
    while(cin>>n)
    {
        _=2;
        if(n==0)
            cout<<0<<endl;
        else if(n==1)
            cout<<2<<endl;
        else
        {
            for(int i=2;i<=n;i++)
            {
                _+=(i-1)*2;
            }
            cout<<_<<endl;
        }
    }
    return 0;
}
