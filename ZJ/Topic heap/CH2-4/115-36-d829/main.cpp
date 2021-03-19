#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s)&&s[0]!='#')
    {
        int Count=0;
        vector<char> v;
        for(int i=0;i<s.length();i++)
        {
            v.push_back(s[i]);
        }
        if(next_permutation(v.begin(),v.end()))
        {
            for(vector<char>::iterator it=v.begin();it!=v.end();it++)
            {
                printf("%c",*it);
            }
            printf("\n");
        }
        else
        {
            printf("No Successor\n");
        }

    }
    return 0;
}
