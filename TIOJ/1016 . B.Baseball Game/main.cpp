#include <iostream>
#include <string>
using namespace std;
string s;
bool base[4],is_red_attack;
int blue_goal,red_goal,out;
inline void get_goal()
{
    if(is_red_attack) red_goal++;
    else blue_goal++;
}
inline void Walk()
{
    if(base[1])
    {
        if(base[2])
        {
            if(base[3]) get_goal();
            else base[3]=true;
        }
        else base[2]=true;
    }
    else base[1]=true;
}
inline void hit(int kind)
{
    for(int i=3;i>=1;i--)
        if(base[i])
            if(i+kind>=4)
            {
                base[i]=false;
                get_goal();
            }
            else base[i+kind]=true,base[i]=false;
    base[kind]=true;
}
inline void base_clear()
{
    base[1]=base[2]=base[3]=false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(getline(cin,s,'\n')&&!s.empty())
    {
        is_red_attack=true;
        blue_goal=red_goal=out=0;
        base_clear();
        for(auto now:s)
        {
            if(now=='K'||now=='O') out++;
            else if(now=='W') Walk();
            else if(now=='S') hit(1);
            else if(now=='D') hit(2);
            else if(now=='T') hit(3);
            else if(now=='H')
            {
                for(auto player:base)
                    if(player) get_goal();
                base_clear();
                get_goal();
            }
            if(out==3){is_red_attack=!is_red_attack,out=0;base_clear();}
        }
        cout<<red_goal<<' '<<blue_goal<<'\n';
    }
    return 0;
}
