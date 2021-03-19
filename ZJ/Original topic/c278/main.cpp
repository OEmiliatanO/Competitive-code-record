#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main()
{
    for(int N;scanf("%d",&N)!=EOF&&N;)
    {
        int sum=0;
        v.resize(N);
        for(int i=0;i<N&&scanf("%d",&v[i]);i++);
        sort(v.begin(),v.end());
        for(int i=1;i<N;sum+=(v[i]-v[i-1]),i+=2);
        printf("%d\n",sum);
    }
    return 0;
}
