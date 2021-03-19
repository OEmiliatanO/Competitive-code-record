#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
    string in;
    while(getline(cin,in)&&in!="")
    {
        int i;
        for(int j=0;j<in.length();j++)
        {
            for(i=0;ch[i]&&ch[i]!=in[j];i++)
            {
                //printf("infor %d=%c != %c\n",i,ch[i],in[j]);
            }
            if(ch[i])
                putchar(ch[i-1]);
            else
                putchar(in[j]);
        }
        printf("\n");
    }
    return 0;
}
