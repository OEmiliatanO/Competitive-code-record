#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
stack<char> Sy;
stack<LL> Num;

int comput()
{
    if(Num.size()<2||Sy.size()<1||Sy.top()=='(') return -1;
    LL b=Num.top(),a;
    Num.pop();
    a=Num.top();
    Num.pop();
    char ch=Sy.top();
    Sy.pop();
    switch(ch)
    {
    case '+':
        Num.push(a+b);
        break;
    case '-':
        Num.push(a-b);
        break;
    case '*':
        Num.push(a*b);
        break;
    case '/':
        Num.push(a/b);
        break;
    case '%':
        Num.push(a%b);
        break;
    }
    /*cout<<"InComput() Num.top="<<Num.top()<<endl;
    cout<<"InComput() a="<<a<<endl;
    cout<<"InComput() b="<<b<<endl;*/
}

long long strToint(string &s,int &i)
{
    while(s[i]<'0'||s[i]>'9') i++;
    LL re=0,pow=10;
    while(s[i]>='0'&&s[i]<='9')
    {
        re=(re*pow+s[i++]-'0');
        /*cout<<"inside re="<<re<<endl;
        cout<<"pow="<<pow<<endl;*/
    }
    //cout<<"re="<<re<<endl;
    return re;
}
int Priority(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/'||ch=='%')
        return 2;
    else
        return 0;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        while(!Sy.empty())
            Sy.pop();
        while(!Num.empty())
            Num.pop();

        if(s.empty())
            break;
        for(int i=0;i<s.length();)
        {
            if(s[i]=='(')
            {
                Sy.push('(');
                i++;
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
                if(!Sy.empty()&&Priority(Sy.top())>=Priority(s[i]))
                {
                    while(comput()!=-1);
                    Sy.push(s[i++]);
                }
                else
                    Sy.push(s[i++]);
            else if(s[i]==')')
            {
                i++;
                while(comput()!=-1);
                if(!Sy.empty()&&Sy.top()=='(')
                    Sy.pop();
            }
            else if(s[i]==' ')
                i++;
            else
            {
                Num.push(strToint(s,i));
            }
            /*if(!Sy.empty())
                cout<<"Sy.top="<<Sy.top()<<endl;
            else
                cout<<"Sy.top=empty"<<endl;
            if(!Num.empty())
                cout<<"Num.top="<<Num.top()<<endl;
            else
                cout<<"Num.top=empty"<<endl;*/
        }
        while(comput()!=-1);
        cout<<Num.top()<<"\n";
    }
    return 0;
}
