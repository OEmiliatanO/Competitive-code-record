#include <bits/stdc++.h>

using namespace std;


int StrToInt(int *pointInStr,string str)
{
    int theStart=(*pointInStr),point_ch=0;
    char ch[4]{'0'};
    for(;str[*pointInStr]!=' '&&*pointInStr<str.size();(*pointInStr)++)
    {
        if(str[*pointInStr]>='0'&&str[*pointInStr]<='9')
        {
            ch[point_ch]=str[*pointInStr];
            point_ch++;
        }
    }
    return atoi(ch);
}

int main()
{
    string s="";
    int n;
    int pointInStr=0,ans_point;

    while(getline(cin,s))
    {
        pointInStr=0;
        n=StrToInt(&pointInStr,s);
        int Arr[n]{0};
        pointInStr++;
        for(int i=1;i<=n;i++)
        {
            int X=StrToInt(&pointInStr,s);
            pointInStr++;
            Arr[i-1]=X;

        }
        sort(Arr,Arr+n);
        if((Arr[n-1]-Arr[0])==(n-1))
        {

            cout<<Arr[0]<<" "<<Arr[n-1]<<" ";

            cout<<"yes"<<endl;
        }
        else
        {

            cout<<Arr[0]<<" "<<Arr[n-1]<<" ";

            cout<<"no"<<endl;
        }
    }
    return 0;
}
