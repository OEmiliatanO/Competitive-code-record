#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char,int> Greek;
    Greek['A']=1;
    Greek['B']=2;
    Greek['G']=3;
    Greek['D']=4;
    Greek['E']=5;
    Greek['#']=6;
    Greek['Z']=7;
    Greek['Y']=8;
    Greek['H']=9;
    Greek['I']=10;
    Greek['K']=20;
    Greek['L']=30;
    Greek['M']=40;
    Greek['N']=50;
    Greek['X']=60;
    Greek['O']=70;
    Greek['P']=80;
    Greek['Q']=90;
    Greek['R']=100;
    Greek['S']=200;
    Greek['T']=300;
    Greek['U']=400;
    Greek['F']=500;
    Greek['C']=600;
    Greek['$']=700;
    Greek['W']=800;
    Greek['3']=900;
    string s;
    while(cin>>s)
    {
        if(s[0]=='.')
            break;
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            if(Greek.find(s[i])!=Greek.end())
            {
                sum+=Greek.find(s[i])->second;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
