#include <iostream>
#include <string>
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
using namespace std;
string ADD(const string &a,const string &b)
{
    int al=a.length(),bl=b.length(),carry=0,i,j,sum;
    string result,r;
    for(i=al-1,j=bl-1;i>=0&&j>=0;i--,j--)
    {
        sum=(a[i]-'0'+b[j]-'0')+carry;
        carry=sum/10;
        result+=(char)(sum%10+'0');
        //cout<<result<<'\n';
    }
    for(int p=max(i,j);p>=0;p--)
    {
        sum=(al>bl?a[p]:b[p])-'0'+carry;
        carry=sum/10;
        //printf("sum=%d\n",sum);
        //cout<<"carry="<<carry<<'\n';
        result+=(char)(sum%10+'0');
        //cout<<result<<'\n';
    }
    if(carry) result+='1';
    for(int i=result.length()-1;i>=0;i--)
        r+=result[i];
    return r;
}
int main()
{
    string a,b="0";
    for(;cin>>a&&a!="0";)
        b=ADD(a,b);
    cout<<b<<'\n';
    return 0;
}
