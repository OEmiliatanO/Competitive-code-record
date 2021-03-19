#include <cstdio>
#include <string.h>
using namespace std;
char str[105];
int main()
{
    for(;scanf("%s",&str)!=EOF;)
    {
        int length=strlen(str);
        if(str[0]!='-')
        {
            if(4<length)
                if(str[4]>='5')
                    if(str[3]=='9')
                    {
                        if(str[2]=='9'){str[0]++; str[2]='0';}
                        else str[2]++;
                        str[3]='0';
                    }
                    else str[3]++;
        }
        else
        {
            if(5<length)
                if(str[5]>='5')
                    if(str[4]=='9')
                    {
                        if(str[3]=='9'){str[1]++; str[3]='0';}
                        else str[3]++;
                        str[4]='0';
                    }
                    else str[4]++;
        }
        if(str[0]=='-')
            if(!(str[1]=='0'&&str[3]=='0'&&str[4]=='0')) printf("%c%c%c%c%c\n",str[0],str[1],str[2],str[3],str[4]);
            else printf("0.00\n");
        else
            printf("%c%c%c%c\n",str[0],str[1],str[2],str[3]);
    }
    return 0;
}
