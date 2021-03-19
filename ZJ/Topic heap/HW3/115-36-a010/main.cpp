#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int N)
{
    if(N==1||N==0)
        return false;
    else if(N==2)
        return true;
    for(int i=2;i<=(int)sqrt(N);i++)
        if(N%i==0)
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n)
    {
        for(int i=2,time=0;i<=n;time=0,i++)
            if(isPrime(i)&&n%i==0)
            {
                while(n%i==0)
                {
                    n/=i;
                    time++;
                }
                if(time>1) cout<<i<<"^"<<time;
                else cout<<i;
                if(n!=1) cout<<" * ";
            }
        cout<<'\n';
    }
    return 0;
}
