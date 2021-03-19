#pragma warning( disable : 4996 )
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>

using namespace std;

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;

constexpr int MAXD = 2;

class KDT
{
public:
	typedef struct point
	{
		int d[MAXD];
		inline int dis(const point& to) const
		{
			int res = 0;
			for (int i = 0; i < MAXD; ++i) res += abs(d[i] - to.d[i]);
			return res;
		}
		inline bool operator== (const point& p) const
		{
			for (int i = 0; i < MAXD; ++i) if (d[i] != p.d[i]) return false;
			return true;
		}
		inline bool operator< (const point& p) const
		{
			return d[0] < p.d[0];
		}
		inline void read()
		{
			for (int i = 0; i < MAXD && scanf("%d", &d[i]); ++i);
		}
	}pt;
private:
	struct node
	{
		node* l, * r;
		pt pid;
		int s;
		node(const pt& p) : l(0), r(0), pid(p), s(1) {}
		void push_up()
		{
			s = (l ? l->s : 0) + 1 + (r ? r->s : 0);
		}
	}*root;
	struct __cmp
	{
		int sort_id;
		inline bool operator()(const node* rhs, const node* lhs) const
		{
			return operator()(rhs->pid, lhs->pid);
		}
		inline bool operator()(const pt& rhs, const pt& lhs) const
		{
			if (rhs.d[sort_id] != lhs.d[sort_id]) return rhs.d[sort_id] < lhs.d[sort_id];
			for (int i = 0; i < MAXD; ++i)
				if (rhs.d[i] != lhs.d[i]) return rhs.d[i] < lhs.d[i];
			return false;
		}
	}cmp;

	vector<node*> A;
	const double alpha, loga;
	const int INF;
	int maxn, qM;
	priority_queue<pair<int, pt>> pq;

	void clear(node* x)
	{
		if (!x) return;
		clear(x->l);
		clear(x->r);
		delete x;
	}
	inline int size(node* x)
	{
		return x ? x->s : 0;
	}

	node* build(int k, int l, int r)
	{
		if (l > r) return 0;

		int mid = (l + r) >> 1;

		k = (k == MAXD ? 0 : k);
		cmp.sort_id = k;

		nth_element(A.begin() + l, A.begin() + mid, A.begin() + r + 1, cmp);

		node* res = A[mid];
		res->l = build(k + 1, l, mid - 1);
		res->r = build(k + 1, mid + 1, r);
		res->push_up();
		return res;
	}

	inline bool isBad(node* x)
	{
		return (size(x->l) > alpha* x->s) || (size(x->r) > alpha* x->s);
	}

	void flatten(node* x, vector<node*>::iterator& it)
	{
		if (!x) return;
		flatten(x->l, it);
		*it = x;
		flatten(x->r, ++it);
	}

	inline void rebuild(node*& x, int k)
	{
		if ((int)A.size() < x->s) A.resize(x->s);
		typename vector<node*>::iterator it = A.begin();
		flatten(x, it);
		x = build(k, 0, x->s - 1);
	}

	bool insert(node*& x, int k, const point& taget, int dep)
	{
		if (!x)
		{
			x = new node(taget);
			return dep <= 0;
		}
		++(x->s);
		cmp.sort_id = k;
		if (insert((cmp(taget, x->pid) ? x->l : x->r), (k + 1) % MAXD, taget, dep - 1))
		{
			if (!isBad(x)) return true;
			rebuild(x, k);
		}
		return false;
	}
	node* findmin(node* x, int k)
	{
		if (!x) return nullptr;
		if (cmp.sort_id == k) return x->l ? findmin(x->l, (k + 1) % MAXD) : x;

		node* l = findmin(x->l, (k + 1) % MAXD);
		node* r = findmin(x->r, (k + 1) % MAXD);

		if (l && !r) return cmp(l, x) ? l : x;
		if (!l && r) return cmp(r, x) ? r : x;
		if (!l && !r) return x;
		if (cmp(l, r)) return cmp(l, x) ? l : x;
		return cmp(r, x) ? r : x;
	}

	bool erase(node*& x, int k, const pt& taget)
	{
		if (!x) return false;

		if (x->pid == taget)
		{
			if (x->r);
			else if (x->l)
			{
				x->r = x->l;
				x->l = 0;
			}
			else
			{
				delete x;
				x = nullptr;
				return true;
			}
			--(x->s);
			cmp.sort_id = k;
			x->pid = findmin(x->r, (k + 1) % MAXD)->pid;
			return erase(x->r, (k + 1) % MAXD, x->pid);
		}

		cmp.sort_id = k;
		if (erase((cmp(taget, x->pid) ? x->l : x->r), (k + 1) % MAXD, taget)) { --(x->s); return true; }
		return false;
	}
	inline int heuristic(const int h[]) const
	{
		int res = 0;
		for (int i = 0; i < MAXD; ++i) res += h[i];
		return res;
	}

	void nearest(node* x, int k, const pt& taget, int* h, int& mindis)
	{
		if (x == nullptr || heuristic(h) >= mindis) return;
		int dist = x->pid.dis(taget), tmp = h[k];

		if (dist < mindis && !(taget == x->pid))
		{
			pq.emplace(make_pair(dist, x->pid));
			if ((int)pq.size() == qM + 1)
				mindis = pq.top().first, pq.pop();
		}
		if (taget.d[k] < x->pid.d[k])
		{
			nearest(x->l, (k + 1) % MAXD, taget, h, mindis);
			h[k] = abs(taget.d[k] - x->pid.d[k]);
			nearest(x->r, (k + 1) % MAXD, taget, h, mindis);
		}
		else
		{
			nearest(x->r, (k + 1) % MAXD, taget, h, mindis);
			h[k] = abs(taget.d[k] - x->pid.d[k]);
			nearest(x->l, (k + 1) % MAXD, taget, h, mindis);
		}
		h[k] = tmp;
	}

public:

	KDT(const int& INF, double a = 0.75) : root(nullptr), alpha(a), loga(log2(1.0 / a)), INF(INF), maxn(1) {}
	inline void clear()
	{
		clear(root), root = nullptr, maxn = 1;
	}

	inline void build(int n, const pt* p)
	{
		clear(root), A.resize(maxn = n);
		for (int i = 0; i < n; ++i) A[i] = new node(p[i]);
		root = build(0, 0, n - 1);
	}
	inline void insert(const pt& x)
	{
		insert(root, 0, x, __lg	(size(root)) / loga); //
		if (root->s > maxn) maxn = root->s;
	}
	inline bool erase(const pt& p)
	{
		bool d = erase(root, 0, p);
		if (root && root->s < alpha * maxn) rebuild();
		return d;
	}
	inline void rebuild()
	{
		if (root) rebuild(root, 0);
		maxn = root->s;
	}
	inline int nearest(const pt& x, int k = 1)
	{
		qM = k;
		int mindis = INF, h[MAXD] = {};
		nearest(root, 0, x, h, mindis);
		if (pq.size())
		{
			mindis = pq.top().first;
			pq = priority_queue<pair<int, pt> >();
		}
		//assert(mindis >= 0);
		return mindis;
	}
	inline int size()
	{
		return root ? root->s : 0;
	}
};


int main()
{
	KDT kdt(INT_MAX);
	KDT::point tmp;

	constexpr int M = 1e8;
	auto Decode = [&](int a, int ls) { return (ls + a) % M + 1; };
	int Q, last_ans = 0, op, x, y;

	scanf("%d", &Q);
	
	while (Q--)
	{
		scanf("%d %d %d", &op, &x, &y);
		x = Decode(x, last_ans), y = Decode(y, last_ans);

		tmp.d[0] = x, tmp.d[1] = y;

		if (op == 1)
		{
			kdt.insert(tmp);
		}
		else
		{
			if (kdt.size() == 0)
			{
				puts("0");
				last_ans = 0;
			}
			else
				printf("%d\n", (last_ans = kdt.nearest(tmp)));
		}
	}

	return 0;
}

