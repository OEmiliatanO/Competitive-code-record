#include <iostream>
#include <iomanip>
#define jazz ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
    jazz;
    long int a,i,b,d;
    long long int n,m,v,s;
    while(cin >> n >> m&&n&&m)
    {
        long long int x[100000]={0};
        v=0;
        s=1;
        x[0]=1;
        for(a=1;a<=m;a++)
        {
            for(i=0;i<s;i++)
            {
                x[i]=x[i]*n+v;
                v=x[i]/1000000000;
                x[i]=x[i]%1000000000;
                if(v!=0&&i+1==s)
                s++;
            }
        }

        for(b=s-1;b>=0;b--){
            if(b!=s-1)
            cout << setfill('0') << setw(9) << x[b];
            else
            cout << x[b];
        }
        cout << '\n';
    }

    return 0;
}
