#include <bits/stdc++.h>

using namespace std;

int GCD(int i,int j)
{
    if(i+1==j)
        return 1;
    int ans=1;
    for(int m=2;m<=((i>j)?j:i);)
    {
        if(i%m==0&&j%m==0)
        {
            ans*=m;
            i/=m;
            j/=m;
        }
        else
            m++;
    }
    return ans;
}

int main()
{
    int N;
    while(cin>>N)
    {
        if(N==0)
            break;
        int G=0;

        for(int i=1;i<N;i++)
        {
            for(int j=i+1;j<=N;j++)
            {
                G+=GCD(i,j);
            }
        }
        cout<<G<<endl;
    }
    return 0;
}
