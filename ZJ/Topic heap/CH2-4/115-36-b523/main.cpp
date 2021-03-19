#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> Set;
    string s;
    while(getline(cin,s))
    {
        printf((Set.count(s)?"YES\n":"NO\n"));
        Set.insert(s);
    }
    return 0;
}
