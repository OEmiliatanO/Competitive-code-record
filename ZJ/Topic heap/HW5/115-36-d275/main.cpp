#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.get();
    while(n--)
    {
        int M=0,F=0;
        string s="";
        getline(cin,s);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='M')
                M++;
            else if(s[i]=='F')
                F++;
        }
        if(M==F&&M!=1)
            cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;
    }
    return 0;
}
