#include <cstdio>
#include <cstdlib>
using namespace std;
typedef unsigned int uint;
typedef struct Node
{
    Node *left,*right;
    uint data;
}node;
Node *addnode(node *now,const uint &value)
{
    if(now==NULL)
    {
        now=(Node *)malloc(sizeof(struct Node));
        now->left=now->right=NULL;
        now->data=value;
    }
    else if(now->data>value) now->left=addnode(now->left,value);
    else now->right=addnode(now->right,value);
    return now;
}
void show(node *now)
{
    if(now==NULL) return;
    printf("%u ",now->data);
    show(now->left),show(now->right);
}
void del(node *now)
{
    if(now==NULL) return;
    del(now->left),del(now->right);
    delete now;
}
int main()
{
    uint n,m;
    node *root=NULL;
    for(;scanf("%u",&n)!=EOF;puts(""),root=NULL)
    {
        for(int i=0;i<n&&scanf("%u",&m);i++)
            root=addnode(root,m);
        show(root);
        del(root);
    }
    return 0;
}
