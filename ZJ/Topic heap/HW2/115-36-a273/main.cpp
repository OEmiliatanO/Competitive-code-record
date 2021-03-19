#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    while(cin>>n>>k){
        if(k==0) k=n+1;
        cout<<((n%k==0)?"Ok!":"Impossib1e!")<<endl;
        }
    return 0;
}
