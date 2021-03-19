#include <iostream>
#include <string>
#include <cstring>
#define jazz ios_base::sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define S 0
#define C 1

using namespace std;

int CharCount[2][95];
string s, Compare;
bool Flag;

int main()
{
    jazz;

    while(cin >> s >> Compare && s != "STOP")
    {
        Flag = true;
        memset(CharCount, 0, 190 * sizeof(int));

        for(auto ch : s)
            CharCount[S][ch - 33]++;
        for(auto ch : Compare)
            CharCount[C][ch - 33]++;

        for(int i = 0; i < 95; i++)
            if(CharCount[C][i] != CharCount[S][i])
            {
                cout << "no" << '\n';
                Flag = false;
                break;
            }

        if(Flag)
            cout << "yes" << '\n';
    }
    return 0;
}
