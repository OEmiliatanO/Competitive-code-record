#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define IsEqual(x,y) !strcmp((x),(y))
using namespace std;
//Data Start
typedef vector<int>::iterator V_int_it;
const int _firstValue=-1;
char s[10000];
bool failed;
vector<int> ans;
struct Node
{
    int value;
    Node *left,*right;
    Node():value(_firstValue),left(NULL),right(NULL){};
};
Node *root;
//Data END
void RemoveNode(Node *p)
{
    if(p==NULL) return;
    RemoveNode(p->left);
    RemoveNode(p->right);
    delete p;
}
void addnode(int v,char *s)
{
    int len=strlen(s);
    Node *tmp=root;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='L')
        {
            if(tmp->left==NULL)tmp->left=new Node();
            tmp=tmp->left;
        }
        else if(s[i]=='R')
        {
            if(tmp->right==NULL)tmp->right=new Node();
            tmp=tmp->right;
        }
    }
    if(tmp->value!=_firstValue) failed=true;
    tmp->value=v;
}
bool read()
{
    failed=false;
    RemoveNode(root);
    root=new Node();
    int v;
    while(true)
    {
        if(scanf("%s",s)!=1) return false;
        if(IsEqual(s,"()")) break;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}
bool bfs()
{
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        Node *p=qu.front();qu.pop();
        if(p->value!=_firstValue) ans.push_back(p->value);
        else return false;
        if(p->left!=NULL) qu.push(p->left);
        if(p->right!=NULL) qu.push(p->right);
    }
    return true;
}
int main()
{
    while(read())
    {
        ans.clear();
        if(!failed&&bfs())
        {
            for(V_int_it it=ans.begin();it!=ans.end();it++)
            {
                printf("%d",*it);
                if(it!=--ans.end()) putchar(' ');
            }
            puts("");
        }
        else puts("not complete");
    }
    return 0;
}
