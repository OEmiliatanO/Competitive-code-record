#include <cstdio>
using namespace std;
char s[1001];
int main()
{
    for(int N,diff=0,r=0,b=0;scanf("%d",&N)!=EOF;diff=0)
    {
        getchar();
        for(int i=0;i<N&&scanf("%[^\n]s",s);getchar(),diff+=r*b/2,r=0,b=0,i++)
        {
            for(int j=0;j<N<<1;j+=2)
                if(s[j]=='1') r++;
                else if(s[j]=='2') b++;
        }
        printf("%d\n",N*(N-1)*(N-2)/6-diff);
    }
    return 0;
}
