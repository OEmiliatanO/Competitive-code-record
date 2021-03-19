#include <iostream>
#include <string>
#include <map>
using namespace std;
string s1,s2,s3,s4,s5;
string One="A";
string NUM[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE","THREETEEN"};
map<string,int> m;
int main()
{
    cin>>s1>>s2>>s3>>s4>>s5;cin.ignore();

    if(s2[s2.length()-1]=='S') s2=s2.substr(0,s2.length()-1);
    if(s5[s5.length()-1]=='S') s5=s5.substr(0,s5.length()-1);
    if(s1==One) m.emplace(s2,1);
    else
        for(int j=1;j<=13;j++)
            if(NUM[j]==s1)
            {
                m.emplace(s2,j);
                break;
            }
    if(s4==One) m.emplace(s5,1);
    else
        for(int j=1;j<=13;j++)
            if(NUM[j]==s4)
            {
                m.emplace(s5,j*m[s2]);
                break;
            }
    for(int i=1;i<4;i++)
    {
        cin>>s1>>s2>>s3>>s4>>s5;cin.ignore();
        if(s5[s5.length()-1]=='S') s5=s5.substr(0,s5.length()-1);
        if(s2[s2.length()-1]=='S') s2=s2.substr(0,s2.length()-1);
        if(s4==One) m.emplace(s5,m[s2]);
        else
            for(int j=1;j<=13;j++)
                if(NUM[j]==s4)
                {
                    m.emplace(s5,j*m[s2]);
                    break;
                }
    }
    cin.ignore();
    cin>>s1>>s2>>s3;
    s3=s3.substr(0,s3.length()-1);
    if(s3[s3.length()-1]=='S') s3=s3.substr(0,s3.length()-1);
    cout<<m[s3]<<" "<<s3;
    if(m[s3]>1) cout<<"S";
    return 0;
}
