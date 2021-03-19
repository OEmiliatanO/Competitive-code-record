#include <iostream>
#define jazz ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)

using namespace std;

char buffer[50010];

int main()
{
    jazz;
    streambuf *sbf = cin.rdbuf();
    cin.ignore(25000005, ' ');
    streamsize pos = sbf->pubseekoff(0, cin.cur), endOfstr = sbf->pubseekoff(0, cin.end);
    sbf->pubseekpos(pos), endOfstr -= pos, buffer[50000] = 0;
    while(endOfstr > 50000)
    {
        sbf->sgetn(buffer, 50000);
        cout << buffer;
        endOfstr -= 50000;
    }
    sbf->sgetn(buffer, endOfstr), buffer[endOfstr] = 0;
    cout << buffer << ' '; pos--;
    sbf->pubseekoff(0, cin.beg), buffer[50000] = 0;
    while(pos > 50000)
    {
        sbf->sgetn(buffer, 50000);
        cout << buffer;
        pos -= 50000;
    }
    sbf->sgetn(buffer, pos), buffer[pos] = 0;
    cout << buffer;
    return 0;
}
