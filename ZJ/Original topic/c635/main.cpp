#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int ODD[11],EVEN[11],oi=0,ei=0;
string s;
int x,pe,po;
int main()
{
    stringstream ss;
    char tmp;
    for(bool odd=true;getline(cin,s,'\n');ss.clear(),ss.str(""),odd=true,oi=ei=0)
    {
        ss.str(s);
        while(ss>>x)
        {
            ss>>tmp;
            if(odd) ODD[oi++]=x;
            else EVEN[ei++]=x;
            odd=!odd;
        }
        sort(ODD,ODD+oi);
        sort(EVEN,EVEN+ei);
        odd=true;
        for(pe=po=0;pe<ei||po<oi;odd=!odd)
            if(odd)
            {
                if(po<oi)
                {
                    printf("%d",ODD[po++]);
                    if(pe<ei||po<oi) putchar(',');
                }
            }
            else
            {
                if(pe<ei)
                {
                    printf("%d",EVEN[pe++]);
                    if(pe<ei||po<oi) putchar(',');
                }
            }
        puts("");
    }
    return 0;
}
