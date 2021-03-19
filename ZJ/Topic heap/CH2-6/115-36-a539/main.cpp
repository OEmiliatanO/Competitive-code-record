#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int n;scanf("%d",&n)!=EOF;)
    {
        vector<int> v(n);
        int cnt=0;
        for(int i=0,in;i<n&&scanf("%d",&in);i++)
        {
            v[i]=in;
            for(int j=i-1;j>=0;j--)
                if(v[j]>v[i])
                    cnt++;
        }
        printf("Minimum exchange operations : %d\n",cnt);
    }
    return 0;
}
