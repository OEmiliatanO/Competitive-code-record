#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    int ans=0;

    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a)
        ans++;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a)
        ans++;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a)
        ans++;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a)
        ans++;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a)
        ans++;
    printf("%d",ans);
    return 0;
}
