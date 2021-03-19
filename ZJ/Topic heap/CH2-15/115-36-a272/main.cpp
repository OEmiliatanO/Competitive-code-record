#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int ans[20017]={0,1,2},n;
    for(int i=3;i<20017;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
        ans[i]%=10007;
	}
	while(cin>>n)
    {
        n%=20016;
        cout<<ans[n]<<'\n';
    }
    return 0;
}
