#include <bits/stdc++.h>

using namespace std;

bool IsLeap(int year)
{
    if(year%4==0&&year%100!=0)
        return true;
    else if(year%400==0)
        return true;
    return false;
}

int main()
{
    int year1,year2,month1,month2,day1,day2;
    while(cin>>year1>>month1>>day1)
    {
        cin>>year2>>month2>>day2;

        if(year2<year1)
        {
            int t=year1;
            year1=year2;
            year2=t;
            t=month1;
            month1=month2;
            month2=t;
            t=day1;
            day1=day2;
            day2=t;
        }

        int Month[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
        if(IsLeap(year1)&&month1>2)
        {
            day1+=Month[month1-1]+1;
        }
        else
        {
            day1+=Month[month1-1];
        }
        month1=0;
        if(IsLeap(year2)&&month2>2)
        {
            day2+=Month[month2-1]+1;
        }
        else
        {
            day2+=Month[month2-1];
        }
        month2=0;

        int day_d=0;
        for(int i=year1+1;i<year2;i++)
        {
            day_d+=(IsLeap(i)?366:365);
        }
        //cout<<"day_d"<<day_d<<endl;
        if(year1!=year2)
        {
            if(IsLeap(year1))
            {
                //cout<<"day1="<<day1<<endl;
                //cout<<"day2="<<day2<<endl;
                cout<<day_d+366-day1+day2<<endl;
            }
            else
            {
                //cout<<"day1="<<day1<<endl;
                //cout<<"day2="<<day2<<endl;
                cout<<day_d+365-day1+day2<<endl;
            }
        }
        else if(year1==year2)
        {
            cout<<abs(day2-day1)<<endl;
        }
    }
    return 0;
}
