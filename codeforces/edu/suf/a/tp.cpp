/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Tue Jul 14 23:08:21 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

struct SA {
	static const int Ma = 1e6;
	int sa[Ma], rk[Ma], c[Ma], se[Ma], sv[Ma], heigh[Ma];
	string res;

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
		for (const auto& i : s) sv[cnt++] = i;
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

struct Node {
	int len, id, l, r;
	bool operator < (const Node& b) const {
		if (id != b.id) return id < b.id;
		else if (len != b.len) return len < b.len;
		else if (l != b.l) return l < b.l;
		else return r < b.r;
	}
	void print() const {
		cout << l << ' ' << r << endl;
	}
	void scan() {
		cin >> l >> r;
		len = r - l + 1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	sa.build(s);
	int n; cin >> n;
	vector<Node> a(n);
	for (int i = 0; i < n; i++) {
		a[i].scan();
		a[i].id = sa.lower(s.substr(a[i].l - 1, a[i].len));
	}
	sort(a.begin(), a.end());
	for (const auto& i : a) i.print();

	return 0;
}
