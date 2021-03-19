#include <iostream>
//#include <string>
using namespace std;
//string s1,s2;
char ch;
int t;
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s1;
    cin>>s2;
    cout<<s1;
    cout<<' ';
    cout<<s2;*/
    while(cin.get(ch)&&ch!=' ') cin.unget();
    while(cin.get(ch)&&ch!=EOF) cout<<ch;
    cout<<' ';

    return 0;
}
