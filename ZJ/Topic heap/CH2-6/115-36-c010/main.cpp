#include <bits/stdc++.h>

using namespace std;
typedef int LL;

int main()
{
    multiset<LL> N;
    multiset<LL>::iterator it;
    int len=0;
    for(int in;scanf("%d",&in)!=EOF;)
    {
        len++;
        int cnt=1;
        N.insert(in);
        if(len==1){it=N.begin();printf("%d\n",in);continue;}

        if(len%2)
            if(*it>in)
                printf("%d\n",*(--it));
            else
                printf("%d\n",*it);
        else
            if(*it>in)
                printf("%d\n",(*(--it)+ *(++it))/2);
            else
                printf("%d\n",(*it+ *(++it))/2);
    }
    return 0;
}
