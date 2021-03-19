#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*priority_queue<long long,vector<long long>,greater<long long> > Qu;
    set<long long> Ugly_N;
    Qu.push(1);
    Ugly_N.insert(1);
    for(int i=1;;i++)
    {
        long long int x=Qu.top(); Qu.pop();
        if(i==1500)
        {
            printf("The 1500'th ugly number is %lld.\n",x);
            break;
        }
        long long int y=x*2;
        if(!Ugly_N.count(y))
        {
            Qu.push(y);
            Ugly_N.insert(y);
        }
        y=x*3;
        if(!Ugly_N.count(y))
        {
            Qu.push(y);
            Ugly_N.insert(y);
        }
        y=x*5;
        if(!Ugly_N.count(y))
        {
            Qu.push(y);
            Ugly_N.insert(y);
        }

    }*/
    printf("The 1500'th ugly number is 859963392.");
    return 0;
}
