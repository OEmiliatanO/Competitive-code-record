#include <iostream>

using namespace std;

int main()
{
    long int n;
    bool B;
    while(cin>>n)
    {
        B=false;
        if(n==0)
            cout<<"0"<<endl;
        while(n>0)
        {
            if(n%10!=0)
                B=true;
            if(B)
                cout<<n%10;
            n/=10;
        }
        cout<<endl;
    }
    return 0;
}
