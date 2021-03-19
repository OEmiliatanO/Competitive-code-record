#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a1,a2,a3,a4;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a1>>a2>>a3>>a4;
        if(a2-a1==a3-a2&&a3-a2==a4-a3)
        {
            printf("%d %d %d %d %d\n",a1,a2,a3,a4,a4+a2-a1);
        }else
        {
            printf("%d %d %d %d %d\n",a1,a2,a3,a4,a4*a2/a1);
        }
    }
    return 0;
}
