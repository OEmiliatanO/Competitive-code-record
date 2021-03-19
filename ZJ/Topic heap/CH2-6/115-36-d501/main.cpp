#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    for(int n;scanf("%d",&n)!=EOF;)
    {
        v.resize(n);
        for(int i=0;i<n&&scanf("%d",&v[i]);i++);
        sort(v.begin(),v.end());
        printf("A=");
        if(n&1) printf("%d",v[n>>1]);
        else
            for(int s=v[(n>>1)-1];s<=v[n>>1];s++)
            {
                printf("%d",s);
                if(s<v[n>>1])
                    printf("、");
            }
        printf("\n");
    }
    return 0;
}
