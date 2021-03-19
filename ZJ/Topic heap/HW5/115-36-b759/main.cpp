#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    for(int i=0;i<s.length();i++)
    {
        int j=i;
        cout<<s[j++];
        if(j==s.length())
        {
            j=0;
        }
        while(j!=i)
        {
            cout<<s[j];
            if(j+1==s.length())
            {
                j=0;
            }
            else
            {
                j++;
            }
        }
        cout<<endl;
    }
    return 0;
}
