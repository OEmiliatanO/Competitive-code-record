#include <bits/stdc++.h>

using namespace std;

int lcm_unlimited(int num[],int length,int Max)
{
    int ans=1;
    bool all_is_1=false;

    for(int i=2;!all_is_1;)
    {
        bool have_mul=false,still=true;

        for(int j=0;j<length;j++)
        {
            if(num[j]%i==0&&!have_mul)
            {
                ans*=i;
                num[j]/=i;
                have_mul=true;
            }
            else if(num[j]%i==0)
            {
                num[j]/=i;
            }
        }
        all_is_1=true;
        for(int j=0;j<length;j++)
        {
            if(num[j]!=1)
                all_is_1=false;
            if(num[j]%i==0)
            {
                still=true;
                break;
            }
            else
                still=false;
        }
        if(!still)
            i++;
    }
    if(Max==1)
        return 1;

    return ans;
}

int main()
{
    int N;
    while(cin>>N)
    {
        if(N==0)
            break;
        int num[N]={-1},Max=0;

        for(int i=1;i<=N;i++)
        {
            cin>>num[i-1];
            if(Max<num[i-1])
                Max=num[i-1];
        }

        cout<<lcm_unlimited(num,N,Max)<<endl;
    }
    return 0;
}
