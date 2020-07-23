/*************************************************************************
    > File Name: solve.cpp
    > Author: XeroxAuto
    > Mail: lanzongwei@gmail.com
    > Created Time: 2020-07-19 19:02:15
 ************************************************************************/

#ifndef DEBUG
#pragma GCC optimize(2)
#pragma GCC diagnostic error "-std=c++11"  
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)  
#pragma GCC target("avx","sse2")
#endif

#define SYNC 0

#ifdef GOODOJ
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <chrono>
#include <random>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#else
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <limits>
#include <cassert>
#include <sstream>
#include <iterator>
#include <functional>
#endif
using namespace std;

#define RE register

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

#define cin io
#define cout io


#define endl '\n'
#define fep(i,b,e) for(RE int i=(b);i<(e);++i)
#define rep(i,x) for(RE int i=0;i<(x);++i)
#define rap(i,x) for(auto& i : (x))
#define seg(t) (t).begin(), (t).end()
#define ep emplace_back
#define mkp make_pair
#define qxx(i,x) for(RE int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x))&(x))
#define getchar() getchar_unlocked()
#ifdef DEBUG
void err(istream_iterator<string>){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ';
	err(++it, args...);
}
#define debug(args...) {string _s=#args;replace(seg(_s),',',' ');\
cerr<<"DEBUG:";istringstream it(_s);\
err(istream_iterator<string>(it), args);cerr<<endl;}
#else
#define debug(...)
#endif

template<typename T> inline bool cmax(T& a,const T& b) {return a<b?a=b,1:0;}
template<typename T> inline bool cmin(T& a,const T& b) {return a>b?a=b,1:0;}

#ifdef GOODOJ
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef __gnu_pbds::priority_queue<int> pq;
#endif
typedef std::string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pa;

const double P = acos(-1.0), eps = 1e-9;
struct point { db x ,y;};
inline int sign(db a) {return a < -eps ? -1 : a > eps;}
#define dot(p1,p2,p3) ((p2.x-p1.x)*(p3.x-p1.x)+(p2.y-p1.y)*(p3.y-p1.y))
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

const int Ma = 3e5 + 100, inf = 0x3f3f3f3f, mod = 1e9 + 7;

bool vis[Ma];

struct Node {
	int v, nex;
} node[Ma * 2];

int head[Ma], cnt;

void init() {
	memset(head, -1, sizeof head);
	cnt = 0;
}

inline void add(const int& u, const int& v) {
	node[cnt].v = v, node[cnt].nex = head[u];
	head[u] = cnt++;
}

int ans;

void dfs (int u) {
	qxx(i, u) if (!vis[node[i].v])
		vis[node[i].v] = true, ++ans, dfs(node[i].v);
    head[u] = -1;
}

inline void read(int& x) {
	char c;
    for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

signed main() {
	#if SYNC==1
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
	init();
	int n, m; read(n), read(m);
   	while (m--) {
		RE int t, x, y; read(t);
		if (t == 1) {
			read(x);
			if (!vis[x]) ++ans, vis[x] = true, dfs(x);
		} else {
			read(x), read(y);
			if (x == y) {
				if (!vis[x]) ++ans, vis[x] = true, dfs(x);
			} else {
				int tt = (int)vis[x] + vis[y];
				if (tt == 1) {
					++ans;
					vis[x] = vis[y] = true;
					dfs(x); dfs(y);
				} else if (tt == 0) {
					add(x, y);
					add(y, x);
				}
			}
		}
		cout << ans << endl;
	}

    return 0;
}

