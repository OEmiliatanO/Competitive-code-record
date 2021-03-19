#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n<=10)
            printf("%d\n",n*6);
        else if(n<=20)
            printf("%d\n",60+(n-10)*2);
        else if(n<=40)
            printf("%d\n",80+(n-20));
        else
            printf("100\n");
    }
    return 0;
}
