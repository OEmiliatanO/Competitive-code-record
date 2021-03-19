#include <bits/stdc++.h>

using namespace std;

string Ord(int N)
{
    N%=100;
    if(N>=11&&N<=20) return "th";
    int x=N%10;
    if(x==1) return "st";
    else if(x==2) return "nd";
    else if(x==3) return "rd";
    else return "th";
}

int main()
{
    int n,i=1;
    set<long long> H_N;
    long long Humble_num[5843];
    H_N.insert(1);
    for(set<long long>::iterator it=H_N.begin();it!=H_N.end()&&i<=5842;it++,i++)
    {
        long long x=(*it),x2=x*2;
        Humble_num[i]=*it;
        if(!H_N.count(x2))
        {
            H_N.insert(x2);
        }
        x2=x*3;
        if(!H_N.count(x2))
        {
            H_N.insert(x2);
        }
        x2=x*5;
        if(!H_N.count(x2))
        {
            H_N.insert(x2);
        }
        x2=x*7;
        if(!H_N.count(x2))
        {
            H_N.insert(x2);
        }
    }
    while(scanf("%d",&n)&&n)
    {
        cout<<"The "<<n<<Ord(n)<<" humble number is "<<Humble_num[n]<<"."<<endl;
    }

    return 0;
}
