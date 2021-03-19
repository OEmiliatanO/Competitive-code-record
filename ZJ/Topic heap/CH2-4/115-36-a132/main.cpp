#include <bits/stdc++.h>

using namespace std;

string Tobin(int n,int &Count)
{
    string s="",result="";
    while(n!=0)
    {
        char ch=(char)((n%2)+'0');
        s+=ch;
        if(ch=='1')
            Count++;
        n/=2;
    }
    for(int i=s.length()-1;i>=0;i--)
        result+=s[i];
    return result;
}

int main()
{
    for(int I;scanf("%d",&I)&&I;)
    {
        int Count=0;
        string Out=Tobin(I,Count);
        cout<<"The parity of "<<Out<<" is "<<Count<<" (mod 2).\n";
    }
    return 0;
}
