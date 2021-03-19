#include <cstdio>
using namespace std;
using int64=long long;
const int MAXN=500001;
int64 seg_tree[MAXN<<2];
int lazy[MAXN<<2],arr[MAXN];
void build(int left,int right,int root)
{
    if(left==right) seg_tree[root]=arr[left];
    else
    {
        int mid=(left+right)>>1;
        build(left,mid,root<<1);
        build(mid+1,right,root<<1|1);
        seg_tree[root]=seg_tree[root<<1]+seg_tree[root<<1|1];
    }
}
void push_down(int left,int right,int root)
{
    int mid=(left+right)>>1;
    seg_tree[root<<1]+=lazy[root]*(mid-left+1);
    seg_tree[root<<1|1]+=lazy[root]*(right-mid);
    lazy[root<<1]+=lazy[root];
    lazy[root<<1|1]+=lazy[root];
    lazy[root]=0;

}
void updata(int left,int right,int root,int l,int r,int val)
{
    if(l<=left&&right<=r)
    {
        lazy[root]+=val;
        seg_tree[root]+=val*(right-left+1);
    }
    else
    {
        int mid=(left+right)>>1;
        if(lazy[root]) push_down(left,right,root);
        if(l<=mid) updata(left,mid,root<<1,l,r,val);
        if(mid<r) updata(mid+1,right,root<<1|1,l,r,val);
        seg_tree[root]=seg_tree[root<<1]+seg_tree[root<<1|1];
    }
}
int64 Qu(int left,int right,int root,int l,int r)
{
    int mid=(left+right)>>1;
    if(l<=left&&right<=r) return seg_tree[root];
    if(r<left||right<l) return 0;
    if(lazy[root]) push_down(left,right,root);
    return Qu(left,mid,root<<1,l,r)+Qu(mid+1,right,root<<1|1,l,r);
}
int main()
{
    int N,Q,x,y,k;
    scanf("%d",&N);
    for(int i=1;i<=N&&scanf("%d",&arr[i]);i++);
    build(1,N,1);
    scanf("%d",&Q);
    for(int i=0,v;i<Q&&scanf("%d",&v);i++)
    {
        if(v==1)
        {
            scanf("%d %d %d",&x,&y,&k);
            updata(1,N,1,x,y,k);
        }
        else
        {
            scanf("%d %d",&x,&y);
            printf("%lld\n",Qu(1,N,1,x,y));
        }
    }
    return 0;
}
