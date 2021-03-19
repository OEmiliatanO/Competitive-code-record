#include <cstdio>
using namespace std;
char s[200001],key[10000001],ch;
int N,M;
char Set[256];
int inputInt()
{
    int n=0;
    while(~(ch=getchar())&&ch!=' '&&ch!='\n')
        n=n*10+ch-'0';
    return n;
}
int main()
{
    N=inputInt();
    M=inputInt();
    for(int i=0;i<10;i++) Set[i+'0']=i+'0';
    for(int i=0;i<26;i++) Set[i+'a']=i+'a',Set[i+'A']=i+'A';
    for(int i=0;(ch=getchar())&&ch!='\n'&&i<N;i++) s[i]=ch;
    for(int i=0;(ch=getchar())&&ch!='\n'&&i<M;i++) key[i]=ch;
    for(int i=0;(ch=getchar())&&ch!='\n'&&i<M;i++)
    {
        for(int j=0;j<10;j++)
            if(Set[j+'0']==key[i]) Set[j+'0']=ch;
        for(int j=0;j<26;j++)
        {
            if(Set[j+'a']==key[i]) Set[j+'a']=ch;
            if(Set[j+'A']==key[i]) Set[j+'A']=ch;
        }
    }
    for(int i=0;i<N;i++) putchar(Set[s[i]]);
    return 0;
}
