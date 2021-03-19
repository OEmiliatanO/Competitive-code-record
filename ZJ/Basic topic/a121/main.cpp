#include <bits/stdc++.h>
using namespace std;

inline bool isPrime(int n)
{
    if(n==1) return false;
    else if(n==2||n==3||n==5||n==7) return true;
    else if(n&1==0) return false;
    int top=sqrt(n);
    for(int i=2;i<=top;i++)
        if(n%i==0)
            return false;
    return true;
}

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    int a, b, i,_count;
    while (~scanf("%d %d",&a,&b))
    {
        _count=0;
        for (i = a; i <= b; i++)
        {
            if(isPrime(i))
            {
                _count++;
            }
        }
        printf("%d\n",_count);
    }
    return 0;
}
