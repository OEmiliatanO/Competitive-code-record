#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

int numbers[9][1];
set<int> S_col[9],S_row[9],S_block[3][3];
void SetNumber(int x,int y,int N)
{
    S_block[x/3][y/3].insert(N);
    S_col[x].insert(N);
    S_row[y].insert(N);
}
int main()
{
    while(scanf("%d%d%d%d%d%d%d%d%d",&numbers[0][0],&numbers[1][0],&numbers[2][0],&numbers[3][0],&numbers[4][0],&numbers[5][0],&numbers[6][0],&numbers[7][0],&numbers[8][0])==9)
    {
        for(int i=0;i<9;i++)
        {
            S_col[i].clear();
            S_row[i].clear();
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                S_block[i][j].clear();
            }
        }
        for(int i=0;i<9;i++)
        {
            SetNumber(i,0,numbers[i][0]);
        }
        for(int y=1;y<9;y++)
        {
            for(int x=0;x<9;x++)
            {
                int In;
                scanf("%d",&In);
                SetNumber(x,y,In);
            }
        }
        bool Flag=true;
        for(int i=0;i<9;i++)
        {
            if(S_col[i].size()!=9||S_row[i].size()!=9) {Flag=false;}
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(S_block[i][j].size()!=9) {Flag=false;}
            }
        }

        if(Flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
