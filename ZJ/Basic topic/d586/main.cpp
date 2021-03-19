#include <iostream>
#include <string>
using namespace std;
char NumToAlpha[]=" mjqhofawcpnsexdkvgtzblryui";
int AlphaToNum[256];
char AlphaToNum_[]="uzrmatifxopnhwvbslekycqjgd";
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    for(int i=0;i<26;i++)
        AlphaToNum[AlphaToNum_[i]]=i+1;
    int n;
    cin>>n;
    for(int m,len,sum=0;n--&&cin>>m;sum=0)
    {
        cin.ignore();
        getline(cin,s,'\n');
        len=s.length();
        for(int i=0;i<len;)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int n=0;
                while(s[i]>='0'&&s[i]<='9')
                    n=n*10+s[i++]-'0';
                cout<<NumToAlpha[n];
            }
            else if(s[i]>='a'&&s[i]<='z') sum+=AlphaToNum[s[i++]];
            else i++;
        }
        if(sum) cout<<sum;
        cout<<'\n';
    }
    return 0;
}

