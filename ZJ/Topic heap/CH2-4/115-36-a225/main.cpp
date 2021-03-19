#include <bits/stdc++.h>

using namespace std;

bool compare(int a,int b)
{
    if(a%10!=b%10)
        return a%10<b%10;
    return a>b;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n]{0};
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++)
        {
            printf("%d",*(arr+i));
            if(i!=n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
