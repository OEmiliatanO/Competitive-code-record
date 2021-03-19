#include <bits/stdc++.h>

using namespace std;

double GetDis(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    for(int n,All_in_Circle,Part_in_Circle;scanf("%d",&n)!=EOF&&n;)
    {
        All_in_Circle=0,Part_in_Circle=0;
        double r=n-0.50;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int Points_In_Circle=0;
                for(int X=j;X<=j+1;X++)
                    for(int Y=i;Y<=i+1;Y++)
                        if(GetDis(X,Y,0,0)<r)
                            Points_In_Circle++;

                if(Points_In_Circle==4)
                    All_in_Circle++;
                else if(Points_In_Circle>0)
                    Part_in_Circle++;
            }
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,Part_in_Circle*4);
        printf("There are %d cells completely contained in the circle.\n\n",All_in_Circle*4);
    }
    return 0;
}
