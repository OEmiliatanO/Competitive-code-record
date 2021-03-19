/*
#include <bits/stdc++.h>

using namespace std;

int mcp(string s){
  int n = s.length();
  int i = 0, j = 1;
  while (i < n && j < n){
    int k = 0;
    while (k < n && s[i + k] == s[j + k]) ++k;
    if (s[i + k] <= s[j + k]) j += k + 1;
    else i += k + 1;
    if (i == j) ++j;
  }
  int ans = (i < n ? i : j);
  return ans;
}

int main(){
    cin.sync_with_stdio(0);
    //cin.tie(0);

    int T; cin >> T; assert(1 <= T && T <= 100000);

    for (int cs = 1; cs <= T; ++cs){
        string s; cin >> s;
        s.push_back('z' + 1);
        cout << mcp(s) + 1 << '\n';
    }
}
*/
#include <iostream>
#include <string>

using namespace std;

int T, ans;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> s;
        s.push_back('z' + 1);
        ans = 0;

        for (int i = 1; i < s.size() - 1;)
        {
            int l = 0;
            while (s[ans + l] == s[i + l]) ++l;
            if (s[ans + l] > s[i + l])
                swap(ans, i);
            i += l + 1;
            if (i == ans) ++i;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}
