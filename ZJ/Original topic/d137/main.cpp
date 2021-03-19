#include <cstdio>
#include <cmath>

using namespace std;

double _real, _image;

char s[50];
int _index;

void scanf(int &i)
{
    bool neg = false;
    int Int = 0;
    double tmp = 0.0, powCnt = 1;
    if(s[i] == '-')
        neg = true, ++i;
    else if(s[i] == '+')
        ++i;

    while(s[i] && s[i] >= '0' && s[i] <= '9')
        Int = (Int << 3) + (Int << 1) + s[i] - '0', ++i;

    if(s[i] == '.')
    {
        ++i;
        while(s[i] && s[i] >= '0' && s[i] <= '9')
            tmp += (s[i] - '0') * (powCnt *= 0.1), ++i;
    }

    if(s[i] == 'i')
    {
        _image = Int + tmp;
        _image += (Int == 0);
        ++i;
        if(neg) _image = -_image;
    }
    else
    {
        _real = Int + tmp;
        if(neg) _real = -_real;
    }
}

int main()
{
    while(~scanf("%[^\n]s", s) && getchar())
    {
        _index = 0;
        _real = _image = 0.0;

        scanf(_index);
        if(s[_index])
            scanf(_index);

        printf("%.3f\n", sqrt(_real * _real + _image * _image));
    }

    return 0;
}
