#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int arr[29],sum;
stringstream ss;
string s;
int main()
{
    while(getline(cin,s,'\n'))
    {
        sum=0;
        ss.clear();
        ss.str(s);
        for(int i=0;ss>>arr[i];sum+=arr[i++]);
    }
    return 0;
}
