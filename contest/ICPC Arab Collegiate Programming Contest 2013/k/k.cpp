/*************************************************************************
    > File Name: solve.cpp
    > Author: XeroxAuto
    > Mail: lanzongwei@gmail.com
    > Created Time: 2020-07-22 15:11:04
 ************************************************************************/

#define GOODOJ
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
#include <queue>
#include <functional>
#endif
using namespace std;

#define endl '\n'
#define fep(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,x) for(int i=0;i<(x);++i)
#define rap(i,x) for(auto& i : (x))
#define seg(t) (t).begin(), (t).end()
#define ep emplace_back
#define mkp make_pair
#define qxx(i,x) for(int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x))&(x))
#define RE register
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

const int Ma = 1e4 + 100, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int c[Ma], v[Ma], id[Ma], dp[Ma];
int n, m, L;

vector<int> g[Ma];
bool vis[Ma];

int bfs() {
	memset(vis, 0, sizeof vis);
	std::queue<int> q;
	q.emplace(0); q.emplace(0); vis[0] = true;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		int cn = q.front(); q.pop();
		if (t == n - 1) return cn;
		for (const auto& i : g[t]) if (!vis[i])
			vis[i] = true, q.emplace(i), q.emplace(cn + 1);
	}
	return -1;
}

signed main() {
	#if SYNC==0
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
	int T; cin >> T;
	while (T--) {
		cin >> n >> m >> L;
		rep (i, n) cin >> id[i];
		rep (i, m) cin >> c[i] >> v[i];
		memset(dp, inf, sizeof dp);
		sort(id, id + n);
		dp[0] = 0; int mx = id[n - 1] - id[0];
		rep (i, m)
				for (int j = mx; j >= v[i]; j--)
				dp[j] = min(dp[j], dp[j - v[i]] + c[i]);
		rep (i, n) g[i].clear();
		for (int i = 0; i < n; i++) 
			for (int j = i + 1; j < n; j++) if (dp[id[j] - id[i]] <= L)
				g[i].ep(j), g[j].ep(i);
		cout << bfs() << endl;
	}
    
    return 0;
}
