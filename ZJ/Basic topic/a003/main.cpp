#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M,D;
    while(scanf("%d%d",&M,&D)==2)
    {
        int s=(M*2+D)%3;
        if(s==0)
        {
            printf("����\n");
        }
        else if(s==1)
        {
            printf("�g\n");
        }
        else
        {
            printf("��g\n");
        }
    }
    return 0;
}
