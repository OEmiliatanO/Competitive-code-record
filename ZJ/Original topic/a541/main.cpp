#include <iostream>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

__gnu_pbds::gp_hash_table<string, bool> mem;
int N;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N;
    while(N--)
    {
        cin >> s;
        mem[s] = true;
    }

    cin >> N;
    while(N--)
    {
        cin >> s;
        cout << (mem[s] ? "yes" : "no") << '\n';
        mem[s] = true;
    }

    return 0;
}
