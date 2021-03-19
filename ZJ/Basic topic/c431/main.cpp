#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d ",&n);
    //while(cin>>n)
    //{
        int arr[101]={0};
        for(int i=1;i<=n;i++)
        {
            int X;
            scanf("%d ",&X);
            arr[X]++;
        }

        for(int i=1;i<=100;i++)
        {
            if(arr[i]==0)
                continue;
            else if(arr[i]==1)
                printf("%d ",i);
            else
            {
                for(int j=1;j<=arr[i];j++)
                {
                    printf("%d ",i);
                }
            }
        }
        printf("\n");
    //}
    return 0;
}
