#include <bits/stdc++.h>

using namespace std;

bool IsDigit_string(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss;
        int sum=0;
        string _;
        ss<<s;
        while(ss>>_)
        {
            if(IsDigit_string(_))
            {
                int i;
                stringstream buffer;
                buffer<<_;
                buffer>>i;
                sum+=i;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
