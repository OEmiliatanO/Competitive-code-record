#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int N,cnt=0;cin>>N&&N;cnt=0)
    {
        while(N%2) {cnt++; N>>=1;}
        cout<<cnt<<'\n';
    }
    return 0;
}
