#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int all[8],_max=0;
        all[0]=10*a+b+c;
        all[1]=a+10*b+c;
        all[2]=(a*10+b)*c;
        all[3]=a*(b*10+c);
        all[4]=a*b*c;
        all[5]=a+b*c;
        all[6]=a*b+c;
        all[7]=a+b+c;
        for(int i=0;i<8;i++)
        {
            _max=(_max<all[i]?all[i]:_max);
        }
        printf("%d\n",_max);
    }
    return 0;
}
