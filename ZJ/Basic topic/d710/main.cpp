#include <bits/stdc++.h>

using namespace std;
typedef struct _car
{
    string color,brand;
}car;
int main()
{
    for(int n,m;scanf("%d %d",&n,&m)!=EOF;)
    {
        car cars[n];
        for(int i=0;i<n;i++)
        {
            string c,b;
            cin>>b>>c;
            cars[i].color=c;
            cars[i].brand=b;
        }
        for(int i=0;i<m;i++)
        {
            string what,choose;
            cin>>what>>choose;
            if(what[0]=='b')
                for(int i=0;i<n;i++)
                    if(cars[i].brand==choose)
                        cout<<cars[i].brand<<" "<<cars[i].color<<endl;
            else
                for(int i=0;i<n;i++)
                    if(cars[i].color==choose)
                        cout<<cars[i].brand<<" "<<cars[i].color<<endl;
        }
        printf("\n");
    }
    return 0;
}
