#include <bits/stdc++.h>

using namespace std;

int AddAll(int N)
{
    int ans=0;
    for(int i=1;i<N;i++)
    {
        if(N%i==0)
            ans+=i;
    }
    return ans;
}



int main()
{
    int N,S;
    while(cin>>N)
    {
        S=AddAll(N);
        if(S>N)
            printf("‰mÉ\n");
        else if(N>S)
            printf("åkÉ\n");
        else if(N==S)
            printf("Š®‘SÉ\n");
    }
    return 0;
}
