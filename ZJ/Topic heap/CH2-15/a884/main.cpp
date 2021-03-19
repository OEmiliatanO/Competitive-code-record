#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=10000;
char s1[MAXN+1],s2[MAXN+1];
int a[MAXN+1],b[MAXN+1],c[MAXN+1],lenA,lenB,lenC;
bool cmp(int a[],int b[])
{
    for(int i=MAXN;i>=0;i--)
        if(a[i]!=b[i]) return a[i]>b[i];
    return true;
}
int main()
{
    bool cmp_value=true;
    int n;scanf("%d",&n);
    for(;n--&&scanf("%s %s",s1,s2);cmp_value=true)
    {
        memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
        lenA=strlen(s1),lenB=strlen(s2),lenC=0;
        for(int i=0;i<lenA;i++) a[i]=s1[lenA-1-i]-'0';
        for(int i=0;i<lenB;i++) b[i]=s2[lenB-1-i]-'0';
        cmp_value=cmp(a,b);
        lenC=(cmp_value?lenA:lenB);
        if(lenC==lenB) putchar('-');
        for(int i=0;i<lenC;i++)
        {
            c[i]+=(cmp_value?a[i]-b[i]:b[i]-a[i]);
            if(c[i]<0) c[i]+=10,c[i+1]--;
        }
        while(lenC>0&&!c[lenC]) lenC--;
        while(lenC>=0) printf("%d",c[lenC--]);
        puts("");
    }
    return 0;
}
