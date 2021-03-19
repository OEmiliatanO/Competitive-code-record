#include <iostream>

using namespace std;

int main()
{
    int co,ch,ca;
    int p;
    while(cin>>co>>ch>>ca)
    {
        if(co>=10&&ca>=2)
            cout<<co<<" 個餅乾，"<<((co/10>ca/2)?ca/2:co/10)+ch<<" 盒巧克力，"<<ca<<" 個蛋糕。"<<endl;
        else
            cout<<co<<" 個餅乾，"<<ch<<" 盒巧克力，"<<ca<<" 個蛋糕。"<<endl;
    }
    return 0;
}
