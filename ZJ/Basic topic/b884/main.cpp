#include <cstdio>
using namespace std;
int main()
{
    int n;scanf("%d",&n);
    for(int x,y,yee;n--&&scanf("%d %d",&x,&y)&&((yee=100-x-y)|1);puts(""))
        printf(((0>=yee||yee>=100)?"evil!!":(yee<=30?"sad!":(yee<=60?"hmm~~":"Happyyummy"))));
    return 0;
}
