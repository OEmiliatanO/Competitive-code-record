#include <cstdio>
#include <set>
#include <queue>
using namespace std;
typedef long long int64;
typedef struct _obj_l
{
    int64 value,i;
}obj_less;
typedef struct _obj_g
{
    int64 value,i;
}obj_greater;
bool operator < (const obj_less &a,const obj_less &b)
{
    return a.value<b.value;
}
bool operator < (const obj_greater &a,const obj_greater &b)
{
    return a.value>b.value;
}
priority_queue<obj_less> Less;
priority_queue<obj_greater> Greater;
set<int> SET;
obj_greater temp_g;
obj_less temp_l;
int main()
{
    for(int common,in,t=0;scanf("%lld",&common)!=EOF;)
        if(common==1&&scanf("%lld\n",&in))
        {
            temp_g.value=in,temp_g.i=t;
            temp_l.value=in,temp_l.i=t;
            Less.push(temp_l),Greater.push(temp_g);
            t++;
        }
        else if(common==2)
        {
            do
            {
                temp_l=Less.top(),Less.pop();
            }while(SET.count(temp_l.i));
            SET.insert(temp_l.i);
            printf("%d\n",temp_l.value);
        }
        else
        {
            do
            {
                temp_g=Greater.top(),Greater.pop();
            }while(SET.count(temp_g.i));
            SET.insert(temp_g.i);
            printf("%d\n",temp_g.value);
        }
    return 0;
}
