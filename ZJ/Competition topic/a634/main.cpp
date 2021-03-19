#include <bits/stdc++.h>
#define in(x,y) ((x)>=1&&(x)<=8&&(y)>=1&&(y)<=8)
#define abs(x) ((x)<0?(~(x)+1):(x))
using namespace std;
int place_[9][9];
short si,sj,ei,ej,ansP=0,offseti[]={-1,-2,1,2},offsetj[]={-2,-1,2,1},offset[2][4]={{-2,-1,1,2},{-1,1,-2,2}};
set<string> ans;
inline short _dehash(int n)
{
    return n+'a'-1;
}
void dfs(int nowi,int nowj,stack<pair<int,int> > path)
{
    if(nowi==si&&nowj==sj)
    {
        string s="Solution:";
        while(path.size())
        {
            s.push_back(' ');
            s.push_back((char)_dehash(path.top().first));
            s.push_back((char)('0'+path.top().second));
            path.pop();
        }
        ans.insert(s);
        return;
    }
    short nexi,nexj;
    for(int indexi0=0;indexi0<4;indexi0++)
    {
        short flag=abs(offset[0][indexi0]);
        for(int indexj1=(flag==2?0:2);indexj1<(flag==2?2:4);indexj1++)
        {
            nexi=nowi+offset[0][indexi0];
            nexj=nowj+offset[1][indexj1];
            if(in(nexi,nexj)&&place_[nexi][nexj]==place_[nowi][nowj]-1)
            {
                if(place_[nexi][nexj]==0&&nexi!=si&&nexj!=sj) continue;
                assert(nexi>=1&&nexi<=8&&nexj>=1&&nexj<=8);
                path.emplace(make_pair(nexi,nexj));
                dfs(nexi,nexj,path);
                path.pop();
            }
        }
    }
}
void bfs()
{
    queue<pair<int,int> > qu;
    stack<pair<int,int> > tmp;
    qu.emplace(make_pair(si,sj));
    place_[si][sj]=0;
    while(qu.size())
    {
        int i=qu.front().first,j=qu.front().second; qu.pop();
        if(i==ei&&j==ej) break;
        for(int indexi=0;indexi<4;indexi++)
            for(int indexj=(indexi&1);indexj<4;indexj+=2)
            {
                int nexi=i+offseti[indexi],nexj=j+offsetj[indexj];
                if((nexi!=si||nexj!=sj)&&in(nexi,nexj)&&place_[nexi][nexj]==0)
                {
                    assert(nexi>=1&&nexi<=8&&nexj>=1&&nexj<=8);
                    qu.emplace(make_pair(nexi,nexj));
                    place_[nexi][nexj]=place_[i][j]+1;
                }
            }
    }
    printf("The shortest solution is %d move(s).\n",place_[ei][ej]);
    tmp.emplace(ei,ej);
    dfs(ei,ej,tmp);
    for(auto it:ans)
        cout<<it<<'\n';

}

int main()
{
    char s[10];
    while(~scanf("%s",s))
    {
        ans.clear();
        memset(place_,0,sizeof(place_));
        ansP=0;
        si=s[0]-'a'+1;
        sj=s[1]-'0';
        scanf("%s",s);
        ei=s[0]-'a'+1;
        ej=s[1]-'0';
        assert(si>=1&&si<=8&&sj>=1&&sj<=8);
        assert(ei>=1&&ei<=8&&ej>=1&&ej<=8);
        while(scanf("%s",s)&&s[0]!='x')
        {
            assert((s[0]>='a'&&s[0]<='h'));
            assert((s[1]>='1'&&s[1]<='8'));
            place_[s[0]-'a'+1][s[1]-'0']=-1;
        }
        if((si==ei&&sj==ej)) printf("The shortest solution is 0 move(s).\nSolution: %c%d\n",_dehash(si),sj);
        else bfs();
    }
    return 0;
}
