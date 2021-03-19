#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    map<string,int> m;
    ios_base::sync_with_stdio(false);

    while(cin>>N)
    {
        m.clear();
        int i=1;
        string in;
        for(int _=1;_<=N;_++)
        {
            cin>>in;
            if(m.find(in)!=m.end())
            {
                cout<<"Old! "<<m[in]<<"\n";
            }
            else
            {
                cout<<"New! "<<i<<"\n";
                m[in]=i++;
            }
        }
    }
    return 0;
}
