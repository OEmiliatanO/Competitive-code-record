#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a_size,b_size;
    while(scanf("%d",&a_size)!=EOF)
    {
        int dif=0,x,y,c,cnt=0;
        map<int,int> go;
        for(int i=0;i<a_size;i++)
        {
            scanf("%d %d %d",&x,&y,&c);
            go[(y-1)*19+x]=c;
        }
        scanf("%d",&b_size);
        for(int i=0;i<b_size;i++)
        {
            scanf("%d %d %d",&x,&y,&c);
            if(go.find((y-1)*19+x)!=go.end())
            {
                if(go[(y-1)*19+x]==c) dif+=0;
                else dif+=2;
                cnt++;
            }
            else dif++;
        }
        dif+=a_size-cnt;
        printf("%d\n",dif);
    }
    return 0;
}
