#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(!cin)
        {
            if(cin.eof())
                break;
        }
        else if(s.length()<13)
        {
            continue;
        }

        int sumOfFront=0;
        int Count=1;
        for(int i=0;i<s.length()-2;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                sumOfFront+=(s[i]-'0')*Count;
                Count++;
            }
        }
        int C=sumOfFront%11;
        if(C==10&&s[s.length()-1]=='X')
        {
            cout<<"Right"<<endl;
        }
        else if(C==(s[s.length()-1]-'0'))
        {
            cout<<"Right"<<endl;
        }
        else
        {
            for(int i=0;i<s.length()-1;i++)
            {
                cout<<s[i];
            }
            if(C==10)
                cout<<"X"<<endl;
            else
                cout<<C<<endl;
        }
    }
    return 0;
}
