#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long uint64;

const uint64 MOD = 1000000007;

uint64 _hash(const std::string &s, uint64 mod) {
	uint64_t val = 0;
	for (char c : s) val = (val * 131 + c) % mod;
	return val;
}

int main()
{
    //if(_hash("pro", MOD) == _hash("sgh", MOD)) printf("1\n");

    string a;
    unordered_map<int, int> cnt;

    for(int i = 0; i < 26; i++)
    {
        a.push_back(i + 'A');
        for(int j = 0; j < 26; j++)
        {
            a.push_back(j + 'a');
            for(int n = 0; n < 26; n++)
            {
                a.push_back(n + 'a');
                cnt[_hash(a, MOD)]++;
                /*if(_hash(a, MOD) == 5726)
                    cout << a << '\n';*/
                a.pop_back();
            }
            a.pop_back();
        }
        a.pop_back();
    }

    for(auto it : cnt)
        if(it.second >= 2)
            cout << it.first << '\n';

    return 0;
}
