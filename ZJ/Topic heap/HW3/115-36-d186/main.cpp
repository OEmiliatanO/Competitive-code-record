#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    while(1)
    {
        cin>>a>>b;
        if(a==b&&a==0)
            break;
        int left=floor(sqrt(a));
        int right=floor(sqrt(b));
        if(left*left==a) printf("%d\n",right-left+1);
        else if(left*left<a) printf("%d\n",right-left);
    }
    return 0;
}
