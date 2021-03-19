#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v;
        for(int i=n;i>0;i--)
            v.push_back(i);
        do
        {
            for(int i=0;i<v.size();i++)
                cout<<v[i];
            cout<<endl;
        }while(prev_permutation(v.begin(),v.end()));
    }
    return 0;
}
