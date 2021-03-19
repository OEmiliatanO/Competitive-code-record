#include <bits/stdc++.h>

using namespace std;

int Compare_String(string a,string b)
{
    int a_L=a.length();
    int b_L=b.length();
    //cout<<"a_L="<<a_L<<endl;
    //cout<<"b_L="<<b_L<<endl;
    if(a_L>b_L)
        return 1;
    else if(a_L<b_L)
        return 0;

    for(int _a=0,_b=0;_a<a_L;_a++,_b++)
    {
        if(a[_a]<b[_b])
            return 0;
        else if(a[_a]>b[_b])
            return 1;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    //ios::sync_with_stdio(false);
    while(n--)
    {
        string S,In;
        cin>>S;
        //cout<<"S="<<S<<endl;
        for(int i=1;i<=2;i++)
        {
            cin>>In;
            //cout<<"In="<<In<<endl;
            int Flag=Compare_String(S,In);
            //cout<<"F="<<Flag<<endl;
            if(Flag==0) {S=In;}
        }
        cout<<S<<endl;
    }
    return 0;
}
