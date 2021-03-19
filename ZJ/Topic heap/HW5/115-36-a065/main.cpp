#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        for(int i=0;i<6;i++)
        {
            cout<<abs(str[i]-str[i+1]);
        }
        cout<<endl;
    }
    return 0;
}
