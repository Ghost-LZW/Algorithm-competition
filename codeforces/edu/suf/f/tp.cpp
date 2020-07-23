/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Tue Jul 14 23:08:21 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

struct InputOutputStream {
    enum { SIZE = 1000001 };
    char ibuf[SIZE], *s, *t, obuf[SIZE], *oh;
    bool eof;

    InputOutputStream() : s(), t(), oh(obuf), eof(false) {}
    ~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }

    inline char read() {
        if (s == t) t = (s = ibuf) + fread(ibuf, 1, SIZE, stdin);
        return s == t ? -1 : *s++;
    }

    inline InputOutputStream &operator>>(char* x) {
        static char c;
        for (c = read(); isspace(c); c = read())
            if (c == -1) {eof = true; return *this;}
        for (; !isspace(c); c = read()) *x = c, ++x;
        *x = 0;
        return *this;
    }

    template <typename T>
    inline InputOutputStream &operator>>(T &x) {
        static char c;
        static bool iosig;
        for (c = read(), iosig = false; !isdigit(c); c = read()) {
            if (c == -1) {eof = true; return *this;}
            iosig |= c == '-';
        }
        for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
        if (iosig) x = -x;
        return *this;
    }

    inline void print(char c) {
        if (oh == obuf + SIZE) {
            fwrite(obuf, 1, SIZE, stdout);
            oh = obuf;
        }
        *oh++ = c;
    }

    template <typename T>
    inline void print(T x) {
        static int buf[23], cnt;
        if (x != 0) {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
            while (cnt) print((char)buf[cnt--]);
        } else print('0');
    }

    template <typename T>
    inline InputOutputStream &operator<<(const T &x) {
        print(x);
        return *this;
    }

    inline void print(const char* x) {
        for(; *x; x++)
            print(*x);
    }
} io;

#ifndef DEBUG
#define cin io
#define cout io
#endif

#define debug(s) cerr<<#s<<' '<<s<<endl;

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
		for (int j = 1; j <= K; j++) {
			for (int i = 0; i + (1 << j) <= N; i++)
				st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}

	T querry(int l, int r, T (*f)(T, T)) {
		int j = log[r - l + 1];
		return f(st[l][j], st[r - (1 << j) + 1][j]);
	}
};

struct SA {
	static const int Ma = 1e6;
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

	static int f(int a, int b) {
		return a < b ? a : b;
	}

	void calc() {
		int n = res.length();
		int he[n];
		for (int i = 0; i < n; i++)
			he[i] = heigh[sa[i + 1]];
		st.build(he, n, f);
	}

	int lcp(int l, int r) {
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

char s[400100];

int main() {
	cin >> s;
	int ans = 1, n = strlen(s);
	sa.build(s); sa.getH(); sa.calc();
	for (int l = 1; l <= n; l++) {
		for (int i = 0; i + l < n; i += l) if (s[i] == s[i + l]) {
			/*int k1 = i, k2 = i + l;
			int pre = 0, last = 0;
			while (k1 - pre >= 0 and s[k1 - pre] == s[k2 - pre]) 
				++pre;
			while (k1 + last < n and s[k1 + last] == s[k2 + last])
				++last;
			int k = pre + last - 1;*/
			int a = sa.rk[i], b = sa.rk[i + l];
			if (a > b) swap(a, b);
			int k = sa.lcp(a, b - 1);
			int t = i - (l - k % l);
			if (k % l and t >= 0) {
				a = sa.rk[t], b = sa.rk[t + l];
				if (a > b) swap(a, b);
				k = sa.lcp(a, b - 1);
			}
			ans = max(ans, k / l + 1);
		}
	}
	cout << ans << endl;

	return 0;
}
