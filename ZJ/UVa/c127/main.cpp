#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int length=0;
double ScanNumber(string &s,int &i)
{
    int Z=0;
    double mul=0.1,decimal=0.0;
    for(;i<length&&(s[i]>'9'||s[i]<'0');i++);
    for(;i<length&&s[i]<='9'&&s[i]>='0';i++)
        Z=(Z*10)+s[i]-'0';
    if(s[i]=='.')
    {
        i++;
        while(i<length&&s[i]>='0'&&s[i]<='9')
        {
            decimal+=(s[i]-'0')*mul;
            mul*=0.1;
            i++;
        }
    }
    return (double)(Z+decimal);
}
double Mul(string &s,int &i)
{
    switch(s[i])
    {
        case 'M':
            return 1000000;
        case 'm':
            return (1/1000.0);
        case 'k':
            return 1000;
    }
    return 1;
}
int main()
{
    int n,k=1;
    string in;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        int i=0;
        bool _i=false,u=false,p=false;
        double I,U,P;
        getline(cin,in,'\n');
        length=in.length();
        for(;i<length;i++)
            if(in[i]=='=')
            {
                if(in[i-1]=='I'&&!_i)
                {
                    _i=true;
                    I=ScanNumber(in,i);
                    I*=Mul(in,i);
                }
                else if(in[i-1]=='U'&&!u)
                {
                    u=true;
                    U=ScanNumber(in,i);
                    U*=Mul(in,i);
                }
                else if(in[i-1]=='P'&&!p)
                {
                    p=true;
                    P=ScanNumber(in,i);
                    P*=Mul(in,i);
                }
            }
        printf("Problem #%d\n",k++);
        if(_i&&u)
            printf("P=%.2fW",I*U);
        else if(_i&&p)
            printf("U=%.2fV",P/I);
        else if(p&&u)
            printf("I=%.2fA",P/U);
        printf("\n\n");
    }
    return 0;
}
