#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Y;
    while(scanf("%d",&Y)==1)
    {
        if((!(Y%4)&&(Y%100))||!(Y%400))
            printf("‰[”N\n");
        else
            printf("•½”N\n");
    }
    return 0;
}
