/*************************************************************************
    > File Name: solve.cpp
    > Author: XeroxAuto
    > Mail: lanzongwei@gmail.com
    > Created Time: 2020-07-19 15:03:04
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

const int Ma = 501, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n;

int a[Ma][Ma], mx;
bool vis[Ma][Ma];
int sum[12];

void init() {
	for (int i = 2; i < 10; i++)
		sum[i] = sum[i - 1] + 8 * (i - 1) * (i - 1);
}

bool check(int x, int y) {
	return  x <= n and y <= n and x > 0 and y > 0 and !vis[x][y];
}

bool gao(int x, int y, int d, int m, int food, int pre, bool fp=false) {
	food += pre;
	if (food >= sum[m + 1]) ++m, fp = true;

	if (d == mx) {
		if (m == 9) return true;
		else return false;
	}
	if (sum[9] - sum[m] > food + pre * (mx - d) +
			              3 * (mx - d - 1) * (mx - d) / 2) return false;
	if (m == 0) {
		if (d == 0) {
			int mi = x, mj = y;
			for (int i = -3; i <= 3; i++)
				for (int j = -3; j <= 3; j++)
					if (i + j >= 0 and i + j <= 3 and
						check(x + i, y + j) and
						a[x + i][y + j] > a[mi][mj])
						mi = x + i, mj = y + j
			vis[mi][mj] = true;
			if (gao(x, y, d + 1, 1, food, pre + a[mi][mj])) return true;
			vis[mi][mj] = false;
		}

		for (int i = -2; i <= 2; i++)
			for (int j = -2; j <= 2; j++) if (i + j > 0 and i + j <= 2) {
				if (!check(x + i, y + j)) continue;
				if (gao(x + i, y + j, d + 1, 1, food, pre, true))
					return true;
				if (gao(x + i, y + j, d + 1, 0, food, pre)) return true;
			}
	}
}

signed main() {
	#if SYNC==0
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
	init();
	int T; cin >> T;
	while (T--) {
		int x, y;
		cin >> n >> x >> y;
		for (int i = 1; i <= n; i++)
		   for (int j = 1; j <= n; j++)	cin >> a[i][j];
		mx = 9;
		for (; memset(vis, 0, sizeof vis), gao(x, y, 0, 0, 0, 0); ++mx);
		cout << mx << endl;
	}
    
    return 0;
}
