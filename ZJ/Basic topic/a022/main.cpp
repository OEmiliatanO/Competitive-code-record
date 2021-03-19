#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        bool re=true;
        for(int i=0,j=s.length()-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
                re=false;
        }
        cout<<(re?"yes\n":"no\n");
    }
    return 0;
}
