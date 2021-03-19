#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int year;
    while(cin>>year)
    {
        cout<<(year-1911)<<endl;               
    }
    
    return EXIT_SUCCESS;
}
