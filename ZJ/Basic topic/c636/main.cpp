#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string wd[]={"½Þ","¹«","¤û","ªê","¨ß","Às","³D","°¨","¦Ï","µU","Âû","ª¯"};
    for(int y;cin>>y&&y;)
    {
        if(y<0) {y%=12,y+=13;}
        y%=12;
        cout<<wd[y]<<"\n";
    }
    return 0;
}
