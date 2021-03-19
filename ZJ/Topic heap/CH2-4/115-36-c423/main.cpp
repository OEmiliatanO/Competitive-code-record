#include <bits/stdc++.h>

using namespace std;

int GetLength(int n)
{
    int l=0;
    while(n!=0)
    {
        n/=10;
        l++;
    }
    return l;
}

int FindRoot(string S,int Length)
{
    int x=0,root=0;
    for(int i=0;i<Length;i++)
    {
        x+=(S[i]-'0');
    }
    Length=GetLength(x);
    if(Length==1) return x;
    while(Length!=1)
    {
        while(x!=0)
        {
            root+=x%10;
            x/=10;
        }
        Length=GetLength(root);
        if(Length!=1)
        {
            x=root;
            root=0;
        }
    }

    return root;
}
int FindRoot(int N)
{
    int root=0,x=N,L=GetLength(N);
    if(L==1) return N;
    while(L!=1)
    {
        while(x!=0)
        {
            root+=x%10;
            x/=10;
        }
        L=GetLength(root);
        if(L!=1)
        {
            x=root;
            root=0;
        }
    }
    return root;
}

string ToString(int N)
{
    string s;
    stringstream ss;
    ss<<N;
    ss>>s;
    return s;
}

int main()
{
    int N,R;
    string S;
    while(scanf("%d %d",&N,&R)==2&&N&&R)
    {
        cin.ignore();
        getline(cin,S);

        int i=0,i2=0,RR=FindRoot(S,N-1);
        bool Complex=false;
        if(RR==R)
        {
            i2=9;
            Complex=true;
        }
        while(FindRoot(i+RR)!=R)
        {
            i++;
        }
        if(i>9) continue;
        RR=i;
        string RR_Str=ToString(RR),RR_Str2=(Complex?ToString(i2):"");
        set<string> Code;

        Code.insert(RR_Str+S);
        Code.insert(S+RR_Str);
        if(Complex)
        {
            Code.insert(RR_Str2+S);
            Code.insert(S+RR_Str2);
        }

        set<string>::iterator it;
        for(int i=0;i<N-2;i++)
        {
            string Left=S.substr(0,i+1);
            string Right=S.substr(i+1,N-1-(i+1));

            Code.insert(Left+RR_Str+Right);
            if(Complex)
                Code.insert(Left+RR_Str2+Right);
        }
        it=Code.begin();
        Code.erase(it);
        it=Code.end();
        Code.erase(--it);
        if(Code.empty()) continue;
        for(it=Code.begin();it!=Code.end();it++)
        {
            cout<<*it<<endl;
        }
    }
    return 0;
}
