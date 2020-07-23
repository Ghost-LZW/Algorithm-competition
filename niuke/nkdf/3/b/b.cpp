/*************************************************************************
    > File Name: b.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Thu Jul 16 21:04:40 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

class Solution {
public:
    /**
     * 从 1 到 n 每个结点的权值。
     * @param n int整型 
     * @param Edge Point类vector (u, v) 集合
     * @param q int整型 
     * @param Query Point类vector Point.x 为题中 r, Point.y为题中 v
     * @return long长整型vector
     */
	static const int Ma = 100100;
	vector<long> g[Ma * 2];
	int son[Ma], siz[Ma], dep[Ma], top[Ma], rnk[Ma], dfn[Ma], fa[Ma];

	struct SegTree {
		long sum[Ma << 2], lazy[Ma << 2];
		SegTree() {memset(sum, 0, sizeof sum);memset(lazy, 0, sizeof lazy);}
		void add(int o, int l, int r, int L, int R, int val) {
			if (r < L or R < l) return ;
			if(L <= l and r <= R){
				lazy[o] += val;
				sum[o] += (r - l + 1) * val;
				return ;
			}
			int mid = (l + r) >> 1;
			if (lazy[o] and l != r) {
				sum[o << 1] += lazy[o] * (mid - l + 1);
				sum[o << 1 | 1] += lazy[o] * (r - mid);
				lazy[o << 1] += lazy[o];
				lazy[o << 1 | 1] += lazy[o];
				lazy[o] = 0;
			}
			add(o << 1, l, mid, L, R, val);
			add(o << 1 | 1, mid + 1, r, L, R, val);
			sum[o] = sum[o << 1] + sum[o << 1 | 1];
		}
		int querry(int o, int l, int r, int pos){
			if(l == r) return sum[o];
			int mid = (l + r) >> 1;
			if (lazy[o] and l != r) {
				sum[o << 1] += lazy[o] * (mid - l + 1);
				sum[o << 1 | 1] += lazy[o] * (r - mid);
				lazy[o << 1] += lazy[o];
				lazy[o << 1 | 1] += lazy[o];
				lazy[o] = 0;
			}
			if (pos <= mid) return querry(o << 1, l, mid, pos);
			else return querry(o << 1 | 1, mid + 1, r, pos);
    	}
    } st;


	void dfs1(int o) {
		son[o] = -1;
		siz[o] = 1;
		for (const auto& i : g[o]) if (!dep[i]) {
			dep[i] = dep[o] + 1;
			fa[i] = o;
			dfs1(i);
			siz[o] += siz[i];
			if (son[o] == -1 or siz[i] > siz[son[o]]) son[o] = i;
		}
	}
	int cnt;

	void dfs2(int o, int f) {
		top[o] = f;
		dfn[o] = ++cnt;
		rnk[cnt] = o;
		if (son[o] == -1) return ;
		dfs2(son[o], f);
		for (const auto& i : g[o]) if (i != son[o] and i != fa[o])
			dfs2(i, i);
	}

	void build() {
		memset(dep, 0, sizeof dep);
		cnt = 0;
		dep[1] = 1;
		dfs1(1);
		dfs2(1, 1);
	}
	vector<long> ans;

	void rangeAdd(int root, int w, int n) {
		cerr << dfn[root] << ' ' << siz[root] << ' ' << root << endl;
		st.add(1, 1, n, dfn[root], dfn[root] + siz[root] - 1, w);
	}

    vector<long> solve(int n, vector<Point>& Edge, int q, vector<Point>& Query) {
       for (const auto& i : Edge)
		   g[i.x].emplace_back(i.y),
		   g[i.y].emplace_back(i.x);
	   build();
	   ans.resize(n);
	   for (const auto& i : Query) {
		   rangeAdd(i.x, i.y, n);
	   }
	   for (int i = 1; i <= n; i++)
		   ans[rnk[i] - 1] = st.querry(1, 1, n, i);
	   return ans;
    }
} ss;

int main(){
	int n; cin >> n;
	vector<Point> t(n - 1);
	for (auto& i : t) cin >> i.x >> i.y;
	int q; cin >> q;
	vector<Point> tt(q);
	for (auto& i : tt) cin >> i.x >> i.y;
	for (const auto& i : ss.solve(n, t, q, tt))
		cout << i << ' ';

	return 0;
}
