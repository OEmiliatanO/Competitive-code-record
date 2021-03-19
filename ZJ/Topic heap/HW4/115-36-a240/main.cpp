#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int a=1,b=17;
        long int n;
        int sum=0,Num;
        cin>>n;
        while(n--)
        {
            if(a<b)
                a*=10;

            sum+=(a/b);
            //cout<<"sum"<<sum<<endl;
            Num=(a/b);
            //cout<<Num;
            a%=b;
        }
        //cout<<endl;
        cout<<Num<<" "<<sum<<endl;
    }
    return 0;
}
