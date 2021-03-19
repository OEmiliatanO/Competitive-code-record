#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j;
    while(cin>>i>>j)
    {
            cout<<(j-i)/2+(!(i%2)||!(j%2))<<endl;
    }
    return 0;
}
