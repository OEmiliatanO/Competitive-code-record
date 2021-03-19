#include <bits/stdc++.h>

using namespace std;

bool compare(int a,int b)
{
    return a>b;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> Count(26);
    for(vector<int>::iterator it=Count.begin();it!=Count.end();it++)
        *it=0;
    cin.get();
    while(n--)
    {
        string ch;
        getline(cin,ch);
        int L=ch.length();
        for(int i=0;i<L;i++)
        {
            if((ch[i]>='A'&&ch[i]<='Z')||(ch[i]>='a'&&ch[i]<='z'))
            {
                Count[toupper(ch[i])-'A']++;
            }
        }
    }
    vector<int> ahp_sort(Count);
    sort(ahp_sort.begin(),ahp_sort.end(),compare);
    for(vector<int>::iterator it=ahp_sort.begin();it!=ahp_sort.end();it++)
    {
        while(*it==0){it++;}
        if(it==ahp_sort.end())
            break;
        for(int i=0;i<26;i++)
        {
            if(Count[i]==*it)
            {
                printf("%c %d\n",i+'A',*it);
                Count[i]=0;
            }
        }
    }
    return 0;
}
