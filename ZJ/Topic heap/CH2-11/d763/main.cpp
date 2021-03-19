#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include <iostream>
#define LEN 1000
#define N 100
using namespace std;
typedef struct bign{
    int d[4];
    bign operator=(const int n){
        d[0]=n;
        d[1]=d[2]=d[3]=0;
        return*this;
    }
    bign operator+(const bign another){
        bign result;
        for(int i=0;i<4;i++)result.d[i]=d[i]+another.d[i];
        for(int i=0;i<3;i++)if(result.d[i]>=1000000000){
            result.d[i]-=1000000000;
            result.d[i+1]++;
        }
        return result;
    }
    bign operator+=(const bign another){
        *this=*this+another;
        return*this;
    }
}BigN;
BigN _exp2[N],ans;
string s;
int length[N],size;
void dfs(int i,int threshold){
    if(threshold<0){
        ans+=_exp2[i];
        return;
    }
    for(int j=i-1;j>=0;j--)dfs(j,threshold-length[j]);
}
int main(){
    _exp2[0]=1;
    for(int i=1;i<N;i++)_exp2[i]=_exp2[i-1]+_exp2[i-1];
    while(getline(cin,s,'\n')&&s!="0")
    {
        int len=s.length(),temp=0;
        ans=0,size=0;
        for(int i=0;i<=len;i++)
            if(isdigit(s[i]))temp=10*temp+s[i]-48;
            else
            {
                length[size++]=temp;
                temp=0;
            }
        sort(length,length+size);
        for(int i=size-1;i>=0;i--)dfs(i,length[i]);
        if(ans.d[3])printf("%d%09d%09d%09d\n",ans.d[3],ans.d[2],ans.d[1],ans.d[0]);
        else if(ans.d[2])printf("%d%09d%09d\n",ans.d[2],ans.d[1],ans.d[0]);
        else if(ans.d[1])printf("%d%09d\n",ans.d[1],ans.d[0]);
        else printf("%d\n",ans.d[0]);
    }
    return 0;
}
