#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int k;scanf("%d",&k)==1&&k;)
    {
        double Sn=0.0;
        int n=0;
        while(Sn<=k)
            Sn+=1.0/(++n);
        printf("%d\n",n);
    }
    return 0;
}
