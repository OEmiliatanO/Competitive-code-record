#include <bits/stdc++.h>

using namespace std;
bool IsUp(char ch)
{
    if(ch>='A'&&ch<='Z')
        return true;
    else
        return false;
}

int main()
{
    int k;
    string s;
    while(cin>>k)
    {
        cin>>s;

        int s_L=s.length();
        if(s_L==1&&k==1)
        {
            cout<<1<<endl;
            continue;
        }

        int Up_Low_L[s_L]={-1};
        int j=0;
        bool LastAph=IsUp(s[0]); //1=upper 0=lower

        int sum=1;

        for(int i=1;i<s_L;i++)
        {
            if(IsUp(s[i])==LastAph)
            {
                sum++;
            }
            else
            {
                Up_Low_L[j++]=sum;
                LastAph=IsUp(s[i]);
                sum=1;
            }
            if(i==(s_L-1))
            {
                Up_Low_L[j]=sum;
            }
        }

        /*for(int i=0;i<=j;i++)
        {
            cout<<Up_Low_L[i];
        }
        cout<<endl;*/
        int ans=0;
        sum=0;
        for(int i=0;i<=j;i++)
        {
            if(k>Up_Low_L[i])
            {
                if(sum>ans)
                    ans=sum;
                sum=0;
            }
            else if(k==Up_Low_L[i])
            {
                sum+=k;
                if(sum>ans)
                    ans=sum;
            }
            else if(k<Up_Low_L[i])
            {
                sum+=k;
                if(sum>ans)
                    ans=sum;
                sum=k;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
