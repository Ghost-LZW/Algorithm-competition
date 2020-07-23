/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sun Jul 12 13:02:02 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int Ma = 1e5 + 100;

struct SA {
	int rk[Ma], tp[Ma], sa[Ma], k, n;
	void init(int N) {
		k = 0; n = N;
		memset(rk, 0, sizeof(int) * (n + 1));
		memset(tp, 0, sizeof(int) * (n + 1));
		memset(sa, 0, sizeof(int) * (n + 1));
	}


	void gsa(int* c, int n) {
		static function<bool(int, int)> cmp = [&](int i, int j) {
			if (rk[i] != rk[j]) return rk[i] < rk[j];
			else {
				int ri, rj;
				if (i + k < n) ri = rk[i + k];
				else ri = -1;
				if (j + k < n) rj = rk[j + k];
				else rj = -1;
				return ri < rj;
			}
		};
		for (int i = 0; i < n; i++) {
			sa[i] = i;
			rk[i] = c[i];
		}
		for (k = 1; k <= n; k <<= 1) {
			sort(sa, sa + n, cmp);
			tp[sa[0]] = 0;
			for (int i = 1; i < n; i++) {
				tp[sa[i]] = tp[sa[i - 1]] +
							(cmp(sa[i - 1], sa[i]) ? 1 : 0);
			}
			for (int i = 0; i < n; i++)
				rk[i] = tp[i];
		}
	}
}ss;

int c[Ma];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin >> n) {
		ss.init(n + 1);
		string s; cin >> s;
		int a = n, b = n;
		c[n] = n + 1;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'a') {
				if (a == n) c[i] = n;
				else c[i] = a - i;
				a = i;
			} else {
				if (b == n) c[i] = n;
				else c[i] = b - i;
				b = i;
			}
		}
		ss.gsa(c, n + 1);
		for (int i = n - 1; i > -1; --i) cout << ss.sa[i] + 1 << ' ';
		cout << endl;
	}
	
	return 0;
}
