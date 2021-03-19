#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Aph[127];
    string in;
    for(int i='A',_=10;i<='Z';i++)
    {
        if(i=='I') Aph[i]=34;
        else if(i=='O') Aph[i]=35;
        else if(i=='W') Aph[i]=32;
        else if(i=='Z') Aph[i]=33;
        else Aph[i]=_++;
    }

    while(cin>>in&&!in.empty())
    {
        int sum=Aph[in[0]]%10*9+Aph[in[0]]/10;
        for(int i=1,_=8;i<in.length()-1;i++,_--)
        {
            sum+=(in[i]-'0')*_;
        }
        sum+=in[in.length()-1]-'0';
        printf((sum%10?"fake\n":"real\n"));
    }
    return 0;
}
