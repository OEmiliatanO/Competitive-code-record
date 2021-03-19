#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    string AfterCode;
    while(cin>>str)
    {
        cin>>AfterCode;
        if(str[0]<=AfterCode[0])
        {
            cout<<(int)AfterCode[0]-str[0]<<endl;
        }
        else
        {
            cout<<(int)26-str[0]+AfterCode[0]<<endl;
        }
    }
    return 0;
}
