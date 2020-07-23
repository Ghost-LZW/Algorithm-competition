/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Thu Jul 16 15:16:03 2020
 ************************************************************************/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;

const int mod = 998244353, mt = 1000001011, k = 233;

typedef long long ll;

namespace std {
	template<>
   	struct tr1::hash<pair<int, int> > {
		size_t operator () (const pair<int, int>& t) const {
			return t.first + t.second;
		}
    };
}

__gnu_pbds::cc_hash_table<pair<int, int>, int> ha;

inline void insert (const string& t) {
	int len = t.length(); int a = 0, b = 0;
	int ba = 1, bb = 1;
	for (int i = len - 1; i >= 0; --i) {
		a = ((ll) t[i] * ba % mod + a) % mod;
		b = ((ll) t[i] * bb % mt + b) % mt;
		++ha[make_pair(a, b)];
		ba = (ll) ba * k % mod;
		bb = (ll) bb * k % mt;
	}
}

const int Ma = 1e6 + 100;

string s[Ma];
int cnt[Ma];
#define endl '\n'
int nex[Ma];

inline void getNext(int id) {
	int i, j;
	j = nex[0] = -1;
	i = 0;
	int n = s[id].length();
	while (i < n) {
		while (j != -1 and s[id][i] != s[id][j]) j = nex[j];
		nex[++i] = ++j;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		insert(s[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int len = s[i].length();
		int a = 0, b = 0;
		for (int j = 0; j < len; j++) {
			cnt[j] = 0;
			a = ((ll) a * k % mod + s[i][j]) % mod;
			b = ((ll) b * k % mt + s[i][j]) % mt;
			if (ha.find(make_pair(a, b)) == ha.end()) continue;
			cnt[j] += ha[make_pair(a, b)];
		}

		getNext(i);
		
		for (int j = 1; j <= len; j++) {
			if (nex[j] == 0) continue;
			cnt[nex[j] - 1] -= cnt[j - 1];
		}

		for (int j = 0; j < len; j++)
			ans = ((ll) (j + 1) * (j + 1) % mod * cnt[j] % mod + ans) % mod;
	}
	cout << ans << endl;

	
	return 0;
}
