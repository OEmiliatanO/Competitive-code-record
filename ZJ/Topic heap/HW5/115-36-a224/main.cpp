#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        bool Flag=true;
        int alphabet[26]={0};
        for(int i=0;i<s.length();i++)
        {
            s[i]=tolower(s[i]);
        }
        //cout<<s<<endl;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                alphabet[s[i]-'a']++;
        }

        if(s.length()%2==0)
        {
            for(int i=0;i<26;i++)
            {
                if(alphabet[i]%2)
                {
                    Flag=false;
                    break;
                }
            }
        }
        else
        {
            bool FoundOne=false;
            for(int i=0;i<26;i++)
            {
                if(alphabet[i]%2==1&&!FoundOne)
                {
                    FoundOne=true;
                }
                else if(FoundOne&&alphabet[i]%2==1)
                {
                    Flag=false;
                    break;
                }
            }
        }

        if(Flag)
            cout<<"yes !"<<endl;
        else
            cout<<"no..."<<endl;
    }
    return 0;
}
