/*************************************************************************
    > File Name: solve.cpp
    > Author: XeroxAuto
    > Mail: lanzongwei@gmail.com
    > Created Time: 2020-07-19 17:11:21
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

const int Ma = 1e6, inf = 0x3f3f3f3f, mod = 1e9 + 7;

signed main() {
	#if SYNC==0
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
	int T; cin >> T;
	string t = "abacaba";
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		vector<pair<int, int> > res;
		for (int i = 0; i + 6 < s.length(); i++) {
			bool tt = true;
			int pp = 0;
			for (int j = 0; tt and j < 7; j++)
				if (s[i + j] == '?' or s[i + j] == t[j]) {
					if (s[i + j] == '?') ++pp;
				} else tt = false;
			if (tt) {
				res.emplace_back(make_pair(pp, i));
			}
		}
		sort(seg(res));
		bool can = true;
		int cnt = 0;
		while (cnt < res.size() and cnt < 2 and res[cnt].F == 0) ++cnt;
		if (cnt > 1 or res.empty()) can = false;
		else {
			if (cnt == 1) {
				for (int i = 0; i < s.length(); i++)
					if (s[i] == '?') s[i] = 'z';
			} else {
				int pos = res[0].S;
				for (int j = 0; j < 7; j++)
					s[pos + j] = t[j];
				for (int i = 0; i < s.length(); i++)
					if (s[i] == '?') s[i] = 'z';
			}
		}
		if (can) {
			cout << "Yes" << endl;
			cout << s << endl;
		} else cout << "No" << endl;
	}
    
    return 0;
}
