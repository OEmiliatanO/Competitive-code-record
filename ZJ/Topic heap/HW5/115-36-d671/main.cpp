#include <bits/stdc++.h>

using namespace std;

bool IsSquare(int N)
{
    double sqrt_N;
    sqrt_N=sqrt(N);
    if(sqrt_N-(int)sqrt_N>=0.000000001)
        return false;
    return true;
}

int main()
{
    string s;
    int T;
    cin>>T;
    getline(cin,s);
    while(T--)
    {
        int s_L,s_L_sqrt;
        getline(cin,s);
        s_L=s.length();
        s_L_sqrt=sqrt(s_L);
        //cout<<s_L<<endl;
        if(s_L==1)
        {
            cout<<s<<endl;
            continue;
        }

        if(!IsSquare(s_L))
        {
            cout<<"INVALID"<<endl;
            continue;
        }

        for(int i=0;i<s_L_sqrt;i++)
        {
            for(int j=i;j<s_L;j+=s_L_sqrt)
            {
                cout<<s[j];
            }
        }
        cout<<endl;
    }
    return 0;
}
