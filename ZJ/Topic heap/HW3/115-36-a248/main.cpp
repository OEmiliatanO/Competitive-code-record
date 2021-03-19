#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,N;
    bool B;
    while(cin>>a>>b>>N)
    {
        B=false;
        cout<<a/b<<".";
        while(N>0)
        {
            a%=b;
            a*=10;
            while(a<b)
            {
                a*=10;
                N--;
                cout<<"0";
                if(N==0)
                {
                    B=true;
                    break;
                }
            }
            if(B){break;}
            cout<<a/b;
            N--;
        }
        cout<<endl;
    }
    return 0;
}
