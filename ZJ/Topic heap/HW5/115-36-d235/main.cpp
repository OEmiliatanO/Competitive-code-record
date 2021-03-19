#include <bits/stdc++.h>

using namespace std;

int main()
{
    string N;
    while(cin>>N)
    {
        int Osum=0;
        int Esum=0;
        if(N=="0")
            break;

        for(int i=N.length()-1;i>=0;i--)
        {
            if((N.length()-i)%2)
                Osum+=((int)N[i])-'0';
            else
                Esum+=((int)N[i])-'0';
        }

        if(abs(Osum-Esum)%11==0)
            cout<<N<<" is a multiple of 11."<<endl;
        else
            cout<<N<<" is not a multiple of 11."<<endl;
    }
    return 0;
}
