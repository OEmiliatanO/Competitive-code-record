#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int n,m;scanf("%d %d",&n,&m)!=EOF;)
        if(m==0||!((2*n-2)%m)) printf("Go Kevin!!\n");
        else printf("No Stop!!\n");
    return 0;
}
