#include <bits/stdc++.h>


using namespace std;

int main()
{
    int H=-1,M=-1;
    double h,m,result;
    while(1)
    {
        scanf("%d:%d",&H,&M);
        if(H==0&&M==0)
            break;
        h=H*30+M*0.5;
        m=M*6;
        double p=abs(h-m);
        if(p>360-p)
        {
            result=360-p;
        }
        else
        {
            result=p;
        }
        printf("%.3f\n",result);
    }

    return 0;
}
