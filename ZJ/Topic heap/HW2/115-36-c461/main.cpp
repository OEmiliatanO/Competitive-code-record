#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    bool Flag=true,A,B;
    while(cin>>a>>b>>c)
    {
        A=false;
        B=A;
        if(a!=0)
            A=true;
        if(b!=0)
            B=true;

        Flag=true;
        if(a==0&&b==0&&c==0)
        {
            printf("AND\nOR\nXOR\n");
            continue;
        }

        if((A&B)==c)
        {
            printf("AND\n");
            Flag=false;
        }
        if((A|B)==c)
        {
            printf("OR\n");
            Flag=false;
        }
        if((A^B)==c)
        {
            printf("XOR\n");
            Flag=false;
        }
        if(Flag)
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
