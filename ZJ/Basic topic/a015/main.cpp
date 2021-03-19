#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    while(scanf("%d %d",&r,&c)==2&&r&&c)
    {
        int arr[r*c];
        for(int i=0;i<r*c;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<c;i++)
        {
            for(int j=i;j<r*c;j+=c)
            {
                printf("%d ",arr[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
