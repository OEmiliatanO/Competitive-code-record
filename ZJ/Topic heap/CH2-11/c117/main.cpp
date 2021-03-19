#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
int chess[8][8];
string s;
typedef struct _point
{
    int x,y;
}point;
inline int change(char ch)
{
    return (ch>='a'&&ch<='h'?ch-'a':ch-'0'-1);
}
inline bool in(int x,int y)
{
    return x>=0&&x<8&&y>=0&&y<8;
}
int main()
{
    for(point Start,End,now,next;getline(cin,s,'\n');)
    {
        memset(chess,-1,sizeof(chess));
        queue<point> qu;
        Start.y=change(s[0]),Start.x=change(s[1]);
        End.y=change(s[3]),End.x=change(s[4]);
        qu.push(Start),chess[Start.y][Start.x]=0;
        while(!qu.empty())
        {
            now=qu.front(),qu.pop();
            next.x=now.x+2; next.y=now.y+1;
            if(in(now.x+2,now.y+1)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}
            next.x=now.x+2; next.y=now.y-1;
            if(in(now.x+2,now.y-1)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}
            next.x=now.x+1; next.y=now.y-2;
            if(in(now.x+1,now.y-2)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}
            next.x=now.x+1; next.y=now.y+2;
            if(in(now.x+1,now.y+2)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}

            next.x=now.x-2; next.y=now.y+1;
            if(in(now.x-2,now.y+1)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}
            next.x=now.x-2; next.y=now.y-1;
            if(in(now.x-2,now.y-1)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}
            next.x=now.x-1; next.y=now.y+2;
            if(in(now.x-1,now.y+2)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}
            next.x=now.x-1; next.y=now.y-2;
            if(in(now.x-1,now.y-2)&&chess[next.y][next.x]==-1)
                {chess[next.y][next.x]=chess[now.y][now.x]+1; qu.push(next);}

            if(now.x==End.x&&now.y==End.y&&chess[End.y][End.x]!=-1)
                break;
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],chess[End.y][End.x]);
    }
    return 0;
}
