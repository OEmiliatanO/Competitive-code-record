#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct com
{
    char ch;
    int f=0;
}_;
_ Alpha[26];
bool cmp(const _ &A,const _ &B)
{
    if(A.f==B.f)
        return A.ch<B.ch;
    return A.f>B.f;
}
int T;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>T;
    cin.ignore();
    while(T--)
    {
        getline(cin,s,'\n');
        for(int i=0;i<26;i++)
        {
            Alpha[i].f=0;
            Alpha[i].ch=0;
        }
        for(int i=0;i<s.length();i++)
        {
            if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z')) continue;
            s[i]=tolower(s[i]);
            Alpha[s[i]-'a'].f++;
            Alpha[s[i]-'a'].ch=s[i];
        }
        sort(Alpha,Alpha+26,cmp);
        for(int i=0;i<26;i++)
        {
            cout<<Alpha[i].ch;
            if(i+1<26&&Alpha[i].f!=Alpha[i+1].f)
                break;
        }
        cout<<'\n';
    }
    return 0;
}
