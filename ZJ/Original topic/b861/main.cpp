#include <cstdio>
using namespace std;
char s[40000];
short T,chi,tu,flag;
int main()
{
    scanf("%hd",&T);getchar();
    while(T--&&scanf("%[^\n]s",s)&&getchar())
    {
        flag=chi=tu=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='c') chi++;
            else if(s[i]=='t') tu++;
            if(tu>chi) flag|=1;
        }
        if(chi>tu) flag|=2;
        if(flag==0)
            puts("chi pu tao tu pu tao pi");
        else if(flag==1)
            puts("bu chi pu tao dao tu pu tao pi");
        else if(flag==2)
            puts("chi pu tao bu tu pu tao pi");
        else
            puts("chi pu tao bu tu pu tao pi, bu chi pu tao dao tu pu tao pi");
    }
    return 0;
}
