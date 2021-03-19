#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        string s,ans;
        cin>>s;
        int NowCharCount=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[i+1])
            {
                stringstream ss;
                string buffer;
                ss<<NowCharCount;
                ss>>buffer;
                for(int j=0;buffer[j];j++)
                    ans.push_back(buffer[j]);
                ans.push_back(s[i]);
                NowCharCount=1;
            }
            else
            {
                NowCharCount++;
            }
        }
        cout<<(n<ans.size()?s:ans)<<endl;
    }
    return 0;
}
