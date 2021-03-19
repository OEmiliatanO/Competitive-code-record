#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct mine
{
    double val;
    int wi;
}tmp;
vector<mine> vec;
map<string,double> val;
string Atom;
int F,f,W,w;
double ans[5001];
void init()
{
    string atom[]={"Cu", "Zn", "H2O", "Fe", "Si", "Mg", "C", "Pt", "Au", "Ag"};
    double wi[]={1.73, 1.13, 3.72, 0.41, 0.32, 3.46, 2.75, 25000, 12260, 190.629};
    for(int i=0;i<10;i++)
        val[atom[i]]=wi[i];
}

int main()
{
    init();
    while(cin>>F>>f>>W)
    {
        F-=f;
        vec.clear();
        fill(ans,ans+5001,0.0);
        while(cin>>f>>Atom>>w&&Atom!="X")
        {
            if(F>=f)
            {
                F-=f;
                tmp.wi=w;tmp.val=(double)w*val[Atom];
                vec.emplace_back(move(tmp));
            }
            else F=-1;
        }
        for(auto item:vec)
            for(int i=W;i>=item.wi;i--)
                ans[i]=max(ans[i],ans[i-item.wi]+item.val);
        for(f=W;f>=1;f--)
            if(ans[f]>ans[f-1]) break;
        cout<<"kg="<<f<<" value="<<fixed<<setprecision(1)<<ans[W]<<'\n';
    }
    return 0;
}
