#include <cstdio>
using namespace std;
char s[23];
int main()
{
    int N,temp[8];scanf("%d",&N);
    getchar();
    for(int sum=0;N--&&scanf("%[^\n]s",s)&&getchar();sum=0)
    {
        temp[0]=s[0]-'0',temp[1]=s[2]-'0',temp[2]=s[5]-'0',temp[3]=s[7]-'0';
        temp[4]=s[10]-'0',temp[5]=s[12]-'0',temp[6]=s[15]-'0',temp[7]=s[17]-'0';
        for(int i=0,s;i<8;i++)
        {
            temp[i]<<=1;
            s=temp[i]/10+temp[i]%10;
            sum+=s/10+s%10;
        }
        sum+=s[1]-'0'+s[3]-'0'+s[6]-'0'+s[8]-'0'+s[11]-'0'+s[13]-'0'+s[16]-'0'+s[18]-'0';
        if(sum%10==0) puts("Valid");
        else puts("Invalid");
    }
    return 0;
}
