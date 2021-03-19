#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
#define ALL(x) (x).begin(),(x).end()
using namespace std;
set<int> A,B,result;
inline int scanNum(const string &s,int &i)
{
    if(s.empty()) return 0;
    bool positive=true;
    int N=0;
    while(i<s.length()&&s[i]<'0'||s[i]>'9') i++;
    if(i<s.length()&&s[i-1]=='-') positive=false;
    while(i<s.length()&&s[i]>='0'&&s[i]<='9') N=N*10+s[i++]-'0';
    return (positive?N:~N+1);
}
inline void showSet(const set<int> &a)
{
    if(a.empty()) {printf("N"); return;}
    auto END=result.end();
    END--;
    printf("{");
    for(auto it=result.begin();it!=result.end();it++)
    {
        printf("%d",*it);
        if(it!=END) printf(", ");
    }
    printf("}");
}
int main()
{
    int n,i=0;
    string s;
    cin>>n;
    cin.ignore();
    for(int temp;n--&&getline(cin,s,'\n');A.clear(),B.clear(),result.clear(),i=0)
    {
        while(s[i]!='}')
        {
            temp=scanNum(s,i);
            A.insert(temp);
        }
        i++;
        while(s[i]!='}')
        {
            temp=scanNum(s,i);
            B.insert(temp);
        }
        set_union(ALL(A),ALL(B),inserter(result,result.end()));
        showSet(result);
        result.clear();
        printf(", ");

        set_intersection(ALL(A),ALL(B),inserter(result,result.end()));
        showSet(result);
        result.clear();
        printf(", ");

        set_difference(ALL(A),ALL(B),inserter(result,result.end()));
        showSet(result);
        result.clear();
        printf(", ");

        set_symmetric_difference(ALL(A),ALL(B),inserter(result,result.end()));
        showSet(result);
        result.clear();
        printf("\n");
    }
    return 0;
}
