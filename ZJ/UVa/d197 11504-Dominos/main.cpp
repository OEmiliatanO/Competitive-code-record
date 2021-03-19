#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
#define N 100001

vector<int> edge[N];
int dfn[N];
int low[N];
int T;

stack<int> Stack;
bool instack[N];

int component[N];
int indegree[N];
int C;

int n, m;

void init()
{
    for(int i = 1; i <= n; i ++)
    {
        edge[i].clear();
        dfn[i] = 0;
        instack[i] = false;
    }
    while(Stack.size()) Stack.pop();

    T = 0;
    C = 0;
}

void DFS(int u)
{

    dfn[u] = low[u] = ++ T;
    Stack.push(u);
    instack[u] = true;

    for(int i = 0; i < edge[u].size(); i ++)
    {
        int v = edge[u][i];

        if(!dfn[v])
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u], dfn[v]);

    }

    if(dfn[u] == low[u])
    {
        int t;

        C ++;
        indegree[C] = 0;

        do
        {
            t = Stack.top(); Stack.pop();
            instack[t] = false;
            component[t] = C;

        }while(t != u);

    }
}

int main()
{
    int test;

    scanf("%d", &test);
    while(test --)
    {
        scanf("%d %d", &n, &m);

        init();

        while(m --)
        {
            int x, y;

            scanf("%d %d", &x, &y);
            edge[x].push_back(y);
        }

        for(int u = 1; u <= n; u ++)
        {
            if(!dfn[u])
                DFS(u);
        }

        for(int u = 1; u <= n; u ++)
        {
            for(int i = 0; i < edge[u].size(); i ++)
            {
                int v = edge[u][i];
                if(component[u] != component[v])
                    indegree[component[v]] ++;
            }
        }

        int cnt = 0;
        for(int c = 1; c <= C; c ++)
        {
            if(indegree[c] == 0)
                cnt ++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
