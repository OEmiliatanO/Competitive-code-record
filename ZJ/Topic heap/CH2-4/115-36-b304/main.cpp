#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        string s;
        stack<char> St;
        getline(cin,s);

        int L=s.length();
        for(int i=0;i<L;i++)
        {
            if(St.empty())
                St.push(s[i]);
            else
                if(St.top()=='('&&s[i]==')')
                    St.pop();
                else if(St.top()=='['&&s[i]==']')
                    St.pop();
                else
                    St.push(s[i]);
        }
        printf((St.empty()?"Yes\n":"No\n"));
    }
    return 0;
}
