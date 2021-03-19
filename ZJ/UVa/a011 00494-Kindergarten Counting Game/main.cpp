#include <iostream>
#include <string>
using namespace std;
string str;
int length;
bool isAlpha(char ch)
{
    return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
int main()
{
    ios_base::sync_with_stdio(false);
    for(int cnt=0;getline(cin,str,'\n');cnt=0)
    {
        length=str.length();
        for(int i=0;i<length;)
            if(i<length&&!isAlpha(str[i])) {i++; continue;}
            else {cnt++; while(i<length&&isAlpha(str[i]))i++;}
        cout<<cnt<<'\n';
    }
    return 0;
}
