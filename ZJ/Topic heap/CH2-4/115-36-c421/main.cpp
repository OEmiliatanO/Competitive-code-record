#include <bits/stdc++.h>

using namespace std;

multiset<int> Wait_Qu;
void Work_(int i)
{
    if(i==-1&&!Wait_Qu.empty())
    {
        multiset<int>::iterator it=Wait_Qu.begin();
        printf("%d ",*it);
        Wait_Qu.erase(it);
    }
    else if(i==-2&&!Wait_Qu.empty())
    {
        multiset<int>::iterator it=Wait_Qu.end();
        it--;
        printf("%d ",*it);
        Wait_Qu.erase(it);
    }
    else if(i!=-1&&i!=-2&&i)
        Wait_Qu.insert(i);
}

int main()
{
    int x;
    while(scanf("%d",&x)==1&&x)
    {
        Work_(x);
    }
    return 0;
}
