#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        printf("%.2f\n",sqrt(c*c+a*a-b*b));
    }
    return 0;
}
