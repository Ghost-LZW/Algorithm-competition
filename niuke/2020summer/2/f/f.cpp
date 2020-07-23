/*************************************************************************
    > File Name: f.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Mon Jul 13 12:29:25 2020
 ************************************************************************/

#include<bits/stdc++.h>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
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
} io;

const int Ma = 5e3 + 100;

typedef int ll;

inline int id(int l, int r) {
	return l + r | l != r;
}

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

struct SegTree {
	ll ma[Ma * 2];
	void build(int l, int r, ll my) {
		if(l == r) {
			ma[id(l, r)] = max(ma[id(l, r)], lcm(my, l));
			return ;
		}
		int mid = (l + (r - l) / 2);
		build(l, mid, my), build(mid + 1, r, my);
		ma[id(l, r)] = max(ma[id(l, mid)], ma[id(mid + 1, r)]);
	}
	ll querry(int l, int r, int L, int R) {
		if(l > R || r < L)return 0;
		if(L <= l && r <= R){
			return ma[id(l, r)];
		}
		int mid = (l + r) >> 1;
		return max(querry(l, mid, L, R), querry(mid + 1, r, L, R));
	}
};

int n, m;

struct TwTree {
	SegTree node[Ma * 2];
	void build(int l, int r) {
		if(l == r) {
			node[id(l, r)].build(1, m, l);
			return ;
		}
		int mid = (l + (r - l) / 2);
		build(l, mid), build(mid + 1, r);
		merge(id(l, r), id(l, mid), id(mid + 1, r), 1, m);
	}
	void merge(int o, int lt, int rt, int l, int r) {
		if (l > r) return ;
		if(l == r){node[o].ma[id(l, r)] = max(node[lt].ma[id(l, r)], node[rt].ma[id(l, r)]); return ;}
		int mid = (l + r) >> 1;
		merge(o, lt, rt, l, mid);
		merge(o, lt, rt, mid + 1, r);
		node[o].ma[id(l, r)] = max(node[o].ma[id(l, mid)], node[o].ma[id(mid + 1, r)]);
	}

	ll querry(int l, int r, int L, int R, int x1, int x2){
		if(l > R || r < L)return 0;
		if(L <= l && r <= R){
			return node[id(l, r)].querry(1, m, x1, x2);
		}
		int mid = (l + r) >> 1;
		return max(querry(l, mid, L, R, x1, x2), querry(mid + 1, r, L, R, x1, x2));
	}
	ll querry(int x1, int y1, int x2, int y2) {
		return querry(1, n, y1, y2, x1, x2);
	}
}tw;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k; cin >> n >> m >> k;
	tw.build(1, n);
	ll ans = 0;
	for (int i = 1; i <= n - k + 1; i++)
		for (int j = 1; j <= m - k + 1; j++) {
			ans += tw.querry(j, i, j + k - 1, i + k - 1);
		}
	cout << ans << endl;
	
	return 0;
}
