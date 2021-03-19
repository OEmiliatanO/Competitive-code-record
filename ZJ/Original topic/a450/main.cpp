#include <iostream>
#include <algorithm>
#define jazz ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
const int MAXN=1000001;
int N,Q,l,r,a,b;
int hight[MAXN];
int main()
{
    jazz;
    cin>>N>>Q;
    for(int i=0;i<N;i++) cin>>hight[i];
    sort(hight,hight+N);
    while(Q--)
    {
        cin>>a>>b;
        l=lower_bound(hight,hight+N,a)-hight;
        r=upper_bound(hight,hight+N,b)-hight;
        if(r-l>0) cout<<r-l<<'\n';
        else cout<<"The candies are too short"<<'\n';
    }
    return 0;
}
