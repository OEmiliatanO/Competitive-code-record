#include <iostream>
#include <string>
using namespace std;
int Ans[10][4]={{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
int len[10]={1,1,4,4,2,1,1,4,4,2};
int main()
{
    int n;
    for(string M,N;cin>>M>>N;cout<<'\n',n=0)
        if(M=="0"&&N=="0") break;
        else if(N=="0") cout<<"1";
        else if(M=="0"||M=="1") cout<<M;
        else
        {
            if(N.length()>=2) n+=(N[N.length()-2]-'0')*10;
            n+=N[N.length()-1]-'0';
            cout<<Ans[M[M.length()-1]-'0'][n%len[M[M.length()-1]-'0']];
        }
    return 0;
}
