#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int MAXN=500002;
int arr[MAXN],arr_p=0,N,M;
int tree[MAXN*4];
void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}
void build(int l,int r,int now)
{
    if(l==r) arr_p++,tree[now]=arr[arr_p];
    else
    {
        int mid=(l+r)/2;
        build(l,mid,now*2);
        build(mid+1,r,now*2+1);
        tree[now]=max(tree[now*2],tree[now*2+1]);
    }
}
int get_max(int l,int r,int ql,int qr,int now)
{
    int result=~(0x7fffffff)+1;
    if(ql<=l&&qr>=r) result=tree[now];
    else
    {
        int mid=(l+r)/2;
        if(ql<=mid) result=max(result,get_max(l,mid,ql,qr,now*2));
        if(qr>mid) result=max(result,get_max(mid+1,r,ql,qr,now*2+1));
    }
    return result;
}
int get_max_in_tree(int ql,int qr)
{
    if(ql>qr) swap(ql,qr);
    return get_max(1,N,ql,qr,1);
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        arr_p=0;
        for(int i=1;i<=N&&scanf("%d",&arr[i]);i++);
        build(1,N,1);
        scanf("%d",&M);
        for(int i=0,a,b;i<M&&scanf("%d %d",&a,&b);i++)
            printf("%d\n",get_max_in_tree(a,b));
    }
    return 0;
}
