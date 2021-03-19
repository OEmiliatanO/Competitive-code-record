#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string in;
    while(getline(cin,in,'\n'))
    {
        int length=in.length(),sum=0;
        for(int i=0;i<length;i++)
            if(in[i]>='0'&&in[i]<='9')
                sum+=(in[i]-'0');
        if(sum%3)
            cout<<"no"<<'\n';
        else
            cout<<"yes"<<'\n';
    }
    return 0;
}
