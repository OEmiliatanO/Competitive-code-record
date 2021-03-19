#include <iostream>

using namespace std;

int main()
{
    int h,m;
    while(cin>>h>>m)
    {
        h=h*60+m;
        if(h>=450&&h<1020)
            cout<<"At School"<<endl;
        else
            cout<<"Off School"<<endl;
    }
    return 0;
}
