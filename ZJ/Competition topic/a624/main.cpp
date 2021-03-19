#include <cstdio>
#include <cstring>
using namespace std;

char s[31];
bool test1()
{
    int strLen=strlen(s);
    return (strLen>=8);
}
bool test2()
{
    int strLen=strlen(s);
    bool B=false,S=false;
    for(int i=0;i<strLen;i++)
        if(s[i]>='a'&&s[i]<='z')
            S=true;
        else if(s[i]>='A'&&s[i]<='Z')
            B=true;
    return (S&B);
}
bool test3()
{
    int strLen=strlen(s);
    bool letter=false,number=false,symbol=false;
    for(int i=0;i<strLen;i++)
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            letter=true;
        else if(s[i]>='0'&&s[i]<='9')
            number=true;
        else symbol=true;
    return (letter&(number|symbol));
}
int main()
{
    int amount;
    while(~scanf("%[^\n]s",s)&&getchar())
    {
        amount=test1()+test2()+test3();
        if(amount==0)
            puts("This password is WEAK");
        else if(amount==1)
            puts("This password is ACCEPTABLE");
        else if(amount==2)
            puts("This password is GOOD");
        else
            puts("This password is STRONG");
    }
    return 0;
}
