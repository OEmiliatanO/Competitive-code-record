#pragma warning( disable : 4996 )
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAXN = 1e5 + 10;

struct node
{
    static node pmem[MAXN], * ptr;

    int pri, sz, val;
    bool rev;

    node* l, * r;

    node() = default;

    node(int Value)
    {
        val = Value;
        sz = 1;
        pri = rand();
    }
}*root, node::pmem[MAXN], * node::ptr = node::pmem;

int size(node* t)
{
    return t ? t->sz : 0;
}

void pull(node* t)
{
    if (!t) return;
    t->sz = 1;
    if (t->l) t->sz += t->l->sz;
    if (t->r) t->sz += t->r->sz;
}
void push(node* t)
{
    if (!t) return;
    if (!t->rev) return;
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= true;
    if (t->r) t->r->rev ^= true;
    t->rev = false;
}

node* merge(node* a, node* b)
{
    if (!a || !b) return a ? a : b;

    if (a->pri > b->pri)
    {
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    else
    {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void split(node* t, int x, node*& a, node*& b)
{
    if (!t) { a = b = nullptr; return; }
    if (t->rev) push(t);
    if (size(t->l) >= x)
    {
        b = t;
        push(b);
        split(t->l, x, a, b->l);
        pull(b);
    }
    else
    {
        a = t;
        push(a);
        split(t->r, x - size(t->l) - 1, a->r, b);
        pull(a);
    }
}

void print(node* t)
{
    if (t == nullptr) return;
    if (t->rev) push(t);

    print(t->l);
    printf("%d ", t->val);
    print(t->r);
}
void dfs(node *t)
{
    if (t == nullptr) return;
    if (t->rev) push(t);

    printf("now : %d\n", t->val);
    if (t->l != nullptr) printf("L : %d\n", t->l->val);
    if (t->r != nullptr) printf("R : %d\n", t->r->val);
    dfs(t->l);
    dfs(t->r);
}

void insert(int val, int k)
{
    node* l, * r, * now;
    split(root, k, l, r);
    now = new(node::ptr++) node(val);
    root = merge(merge(l, now), r);

    //print(root);
    //puts("");
}

void reverse(int l, int r)
{
    node* tl, * tr;
    split(root, l - 1, tl, root);

    split(root, r - l + 1, root, tr);

    root->rev ^= true;
    root = merge(merge(tl, root), tr);
}

int n, m;

int main()
{
    root = nullptr;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        insert(i, i);
        //puts("中序");
        //print(root);
        //puts("");
        puts("不知道序");
        dfs(root);
        puts("");
    }

    while (m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        reverse(l, r);
        //puts("中序");
        //print(root);
        //puts("");
        puts("不知道序");
        dfs(root);
        puts("");
    }

    print(root);

    return 0;
}
