#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
typedef pair<long double,long double> P;
P arr[maxn + 5];
long double dis(P a , P b) {
    long double x = a.first - b.first , y = a.second - b.second;
    return sqrt(x*x+y*y);
}
int main() {
    int n;
    while(cin >> n)
    {
        long double ans = 0,d;
        long long sum = n * (n-1) * (n-2) / 6;
        for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                d = dis(arr[i],arr[j]);
                ans += d*(n-2);
            }
        }
        cout << fixed <<setprecision(10) << ans /sum <<endl ;
    }
    return 0;
}
