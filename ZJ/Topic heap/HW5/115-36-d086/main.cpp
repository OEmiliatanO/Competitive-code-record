#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s[0]=='0'&&s.length()==1)
            break;
        else if(s.length()==0)
        {
            cout<<"Fail"<<endl;
            break;
        }

        int sum=0;
        bool Flag=true;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
                sum+=toupper(s[i])-'A'+1;
            else
            {
                cout<<"Fail"<<endl;
                Flag=false;
                break;
            }
        }
        if(Flag)
            cout<<sum<<endl;
    }
    return 0;
}
