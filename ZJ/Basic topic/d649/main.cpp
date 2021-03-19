#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    for(int n;cin>>n&&n;)
        for(int i=1;i<=n;i++)
            cout<<string(n-i,'_')<<string(i,'+')<<'\n';
        cout<<'\n';
    return 0;
}
