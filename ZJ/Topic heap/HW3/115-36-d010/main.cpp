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
            printf("�m��\n");
        else if(N>S)
            printf("�k��\n");
        else if(N==S)
            printf("���S��\n");
    }
    return 0;
}
