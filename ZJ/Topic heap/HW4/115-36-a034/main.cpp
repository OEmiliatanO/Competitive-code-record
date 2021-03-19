#include <bits/stdc++.h>

using namespace std;

string ToBin(int N)
{
    string str="";
    while(N>=1)
    {
        str+=(char)(N%2)+'0';
        N/=2;
    }
    string result="";

    for(int i=str.size()-1;i>=0;i--)
    {
        result+=str[i];
    }
    return result;
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<ToBin(n)<<endl;
    }
    return 0;
}
