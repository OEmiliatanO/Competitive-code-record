#include <bits/stdc++.h>

using namespace std;
void print(vector<int> v)
{
    vector<int>::iterator it;
    printf("\nnow vector=[");
    for(it=v.begin();it!=v.end();it++)
    {
        printf("%d",*it);
    }
    printf("]\n");
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]=i+1;
        }
        for(int i=1;i<=m;i++)
        {
            int Kill;
            scanf("%d",&Kill);
            Kill--;
            if(Kill<v.size()&&v[Kill]!=0)
            {
                while(++Kill<v.size()&&!v[Kill]);
                if(Kill<v.size())
                {
                    printf("%d\n",v[Kill]);
                    v[Kill]=0;
                }
                else
                {
                    printf("0u0 ...... ?\n");
                }
            }
            else
            {
                printf("0u0 ...... ?\n");
            }
        }
    }
    return 0;
}
