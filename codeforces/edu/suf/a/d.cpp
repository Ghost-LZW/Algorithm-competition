/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Tue Jul 14 23:08:21 2020
 ************************************************************************/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;

using ll = long long;

#define int ll

#define F first
#define S second

const int inf = 0x3f3f3f3f;

template<typename T>
struct ST {
	static const int K = 25;
	static const int Ma = 1e6;
	int log[Ma + 1];
	T st[Ma][K + 1];
	ST() {
		log[1] = 0;
		for (int i = 2; i <= Ma; i++)
			log[i] = log[i / 2] + 1;
	}
	void build(T* ary, int N, T (*f)(T, T)) {
		for (int i = 0; i < N; i++)
			st[i][0] = ary[i];
		for (int j = 1; j <= K; j++)
			for (int i = 0; i + (1 << j) <= N; i++)
				st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	T querry(int l, int r, T (*f)(T, T)) {
		int j = log[r - l + 1];
		return f(st[l][j], st[r - (1 << j) + 1][j]);
	}
	T sum(int l, int r) {
		T sum = 0;
		for (int j = K; j >= 0; j--)
			if ((1 << j) <= r - l + 1)
				sum += st[l][j], l += (1 << j);
		return sum;
	}
};

struct SA {
	static const int Ma = 1e6;
	static const int Mlog = 25;
	int sa[Ma], rk[Ma], c[Ma], se[Ma], sv[Ma], heigh[Ma];
	string res;
	ST<int> st;
	
	void rsort(int* sa, int n, int m, int *x, int *y = nullptr) {
		memset(c, 0, sizeof(int) * (m + 1));
		for (int i = 0; i < n; i++) ++c[x[i]];
		for (int i = 1; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--)
			y == nullptr ? sa[--c[x[i]]] = i : sa[--c[x[y[i]]]] = y[i];
	}

	bool cmp(int* ck, int w, int n, int a, int b) {
		//static function<int(int)> gg = [&](int t) {
		//	   return t + w < n ? ck[t + w] : -1; }; // 预处理无需
		return ck[a] == ck[b] and
			   ck[a + w] == ck[b + w]; //and gg(a) == gg(b);
	}

	void build(int* r, int n, int m = 130) {
		r[n++] = 0;
		memset(c, 0, sizeof(int) * m);
		memcpy(rk, r, sizeof(int) * n);
		rsort(sa, n, m, rk);
		int *x = rk, *y = se;
		for (int w = 1, p = 1; p < n; m = p, w <<= 1) {
			for (p = 0; p < w; p++) y[p] = n - 1 - p;
			for (int i = 0; i < n; i++) if (sa[i] >= w)
				y[p++] = sa[i] - w;
			rsort(sa, n, m, x, y);
			std::swap(x, y);
			x[sa[0]]= 0; p = 1;
			for (int i = 1; i < n; i++)
				x[sa[i]] = cmp(y, w, n, sa[i - 1], sa[i]) ? p - 1 : p++;
		}
		if (x != rk) swap(rk, se);
	}

	void build(const string& s) {
		int cnt = 0;
		for (const auto& i : s) sv[cnt++] = i - 'a' + 1;
		res = s;
		build(sv, cnt);
	}

	int lower(const string& t) {
		int l = 1, count = res.length();
		int len = t.length();
		while (count > 0) {
			int step = count / 2, mid = l + step;
			string sub = res.substr(sa[mid], len);
			if (sub < t) l = mid + 1, count -= step + 1;
			else count = step;
		}
		return l;
	}

	int upper(const string& t) {
		int l = 1, count = res.length();
		int len = t.length();
		while (count > 0) {
			int step = count / 2, mid = l + step;
			string sub = res.substr(sa[mid], len);
			if (sub <= t) l = mid + 1, count -= step + 1;
			else count = step;
		}
		return l;
	}

	void getH () {
		int n = res.length(), k = 0, j;
		for (int i = 0; i < n; heigh[i++] = k)
			for (k ? --k : 0, j = sa[rk[i] - 1];
				 sv[i + k] == sv[j + k];
				 ++k);
	}

	static int f(int a, int b) {
		return a < b ? a : b;
	}

	ll ghVal () {
		int n = res.length();// int l[n], r[n];
		int he[n + 1]; //, j;
		//__gnu_pbds::cc_hash_table<int, int> hf;
		for (int i = 1; i <= n; i++) {
			he[i - 1] = heigh[sa[i]];
			//if (hf.find(he[i - 1]) == hf.end()) hf[he[i - 1]] = i - 1;
		}
		/* for (int i = 0; i < n; i++) {
			l[i] = i;
			for (j = i - 1; j >= 0; --j) {
				if (he[j] < he[i]) break; //and
					//!(he[j] == he[i] and hf[he[i]] == i) ) break;
				else j = l[j];
			}
			l[i] = j + 1;
		}
		
		for (int i = n - 1; i >= 0; i--) {
			r[i] = i;
			for (j = i + 1; j < n; ++j)
				if (he[j] <= he[i]) break; //and
					//!(he[j] == he[i] and hf[he[i]] == i)) break;
				else j = r[j];
			r[i] = j - 1;
		}
		for (int i = 0; i < n; i++)
			cerr << he[i] << ' ';
		cerr << endl;
		for (int i = 0; i < n; i++)
			cerr << l[i] << ' ' << r[i] << endl; 
		
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += (ll) (i - l[i] + 1) * (r[i] - i + 1) *
				   ((ll) he[i] * (he[i] + 1));*/
		ll ans = 0;
		stack<pair<int, int> > sta;
		he[n] = 0;
		//for (int i = 0; i <= n; i++) cerr << he[i] << ' ';
		//cerr << endl;
		for (int i = 0; i <= n; i++) {
			int ne = he[i], pos = i;
			//cerr << i << endl;
			while (!sta.empty() and sta.top().first >= ne) {
				int res = i - sta.top().second;
				//cerr << "pre : " << sta.top().second << ' ' << i << ' ' << ans << endl;
				pos = sta.top().second;
				int nn = sta.top().first;
				sta.pop();
				int nw = sta.empty() ? 0 : sta.top().first;
				if (nn > ne) ans += (ll) res * (res + 1) / 2
					                             * (nn - max(nw, ne));
				//cerr << "after : " << ans << endl;
			}
			sta.emplace(ne, pos);
		}
		//cerr << ans << endl;

		return ans;
	}

	void getSt() {
		int n = res.length();
		int he[n];
		for (int i = 1; i <= n; i++)
			he[i - 1] = heigh[sa[i]];
		st.build(he, n, f);
	}

	int lcp(int l, int r) {
		//cerr << l << ' ' << r << endl;
		l = rk[l], r = rk[r];
		if (l > r) swap(l, r);
		--r;
		//cerr << st.querry(l, r, f) << endl;
		return st.querry(l, r, f);
	}

	long long count() {
		int n = res.length(); long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans += n - sa[i] - heigh[i - 1];
		return ans;
	}
	string lcbTsub(int tw) {
		int n = res.length(); string ans;
		for (int i = 1; i < n; i++) {
			bool a = n - sa[i] <= tw, b = n - sa[i + 1] <= tw;
			if (a != b and (int) ans.length() < heigh[sa[i + 1]])
				ans = res.substr(sa[i], heigh[sa[i + 1]]);
		}
		return ans;
	}
	string lcbT(const string& s, const string& t) {
		string all = s + char('a' - 1) + t;
		build(all); getH();
		return lcbTsub(t.length());
	}
} sa;

const int Ma = 1e6;
#define endl '\n'

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	sa.build(s); sa.getH();
	int n = s.length();
	ll ans = n * (n + 1) / 2;
	ans += sa.ghVal();
	cout << ans << endl;

	return 0;
}
