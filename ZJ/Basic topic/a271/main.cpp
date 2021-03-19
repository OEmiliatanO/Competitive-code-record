#include <iostream>
#include <string>
using namespace std;
int t,x,y,z,w,n,m,toxic=0,length;
string in;
inline int Eat(int radish)
{
    switch(radish)
    {
        case 0:
            return 0;
        case 1:
            return x;
        case 2:
            return y;
        case 3:
            return 0-z;
        case 4:
            toxic+=n;
            return 0-w;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int radish,i=0;t--;i=0,toxic=0)
    {
        cin>>x>>y>>z>>w>>n>>m;
        cin.ignore();
        getline(cin,in,'\n');
        length=in.length();
        while(i<length)
        {
            radish=in[i]-'0';
            if(m<=0) break;
            m-=toxic;
            if(m<=0) break;
            m+=Eat(radish);
            if(m<=0) break;
            i+=2;
        }
        if(m<=0) cout<<"bye~Rabbit"<<'\n';
        else cout<<m<<'g'<<'\n';
    }
    return 0;
}
