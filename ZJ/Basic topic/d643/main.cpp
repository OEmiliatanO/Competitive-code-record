#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string in;
    int length;
    vector<int> factor;
    bool ans;
    while(cin>>in)
    {
        ans=false;
        length=in.length();
        for(int i=1;i<=length/2;i++)
            if(!(length%i)) factor.push_back(i);
        for(int i=0;i<factor.size();i++)
        {
            string after_cut[length/factor[i]];
            multiset<string> Set;
            for(int m=0;m<length/factor[i];m++)
            {
                for(int j=0;j<factor[i];j++)
                    after_cut[m]+=in[m*factor[i]+j];
                Set.insert(after_cut[m]);
            }
            multiset<string>::iterator it;
            string out;
            for(it=Set.begin();it!=Set.end();it++)
                out+=(*it);
            if(out!=in)
            {
                ans=true;
                cout<<out<<'\n';
            }
        }
        if(!ans)
            cout<<"bomb!\n";
    }
    return 0;
}
