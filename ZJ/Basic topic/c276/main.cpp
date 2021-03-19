#include <cstdio>
using namespace std;
bool Number[10]={0};
char ch,guess[4],ans[4];
int n,A,B;
int main()
{
    for(int i=0;i<4&&scanf("%c",&ch);Number[ch-'0']=true,ans[i]=ch,i++);
    scanf("%d",&n);
    while(n--&&getchar())
    {
        A=B=0;
        for(int i=0;i<4&&scanf("%c",&ch);guess[i]=ch,i++)
            if(Number[ch-'0']) B++;
        for(int i=0;i<4;i++)
            if(guess[i]==ans[i]) A++,B--;
        printf("%dA%dB\n",A,B);
    }
    return 0;
}
