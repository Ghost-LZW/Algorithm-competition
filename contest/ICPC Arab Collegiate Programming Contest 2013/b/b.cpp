/*************************************************************************
    > File Name: solve.cpp
    > Author: XeroxAuto
    > Mail: lanzongwei@gmail.com
    > Created Time: 2020-07-22 15:50:40
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
struct point {
	int x, y;
	void print() {
		cerr << "( " << x << ", " << y << " )" << endl;
	}
};
inline int sign(int a) {return a < 0 ? -1 : a > 0;}
#define dot(p1,p2,p3) ((p2.x-p1.x)*(p3.x-p1.x)+(p2.y-p1.y)*(p3.y-p1.y))
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

const int Ma = 33, inf = 0x3f3f3f3f, mod = 1e9 + 7;
point wd[Ma];

point getp(char t) {
	if (t <= 'E') return {(t - 'A' + 2) * 2, 8};
	int len = t - 'F';
	return {(len % 7 + 1) * 2, (3 - (len / 7)) * 2};
}

string path[Ma][Ma];

inline int left(const point& a, const point& b, const point& c) {
	return sign(cross(a, b, c));
}

inline bool check(point a, point b, point c) {
	int l = 0, r = 0, n = 0;
	for (int i = -1; i < 2; i += 2)
		for (int j = -1; j < 2; j += 2) {
			int res = left(a, b, {c.x + i, c.y + j});
			if (res == 1) l += 1;
			else if (res == -1) r += 1;
			else n += 1;
		}
	if (l != 0 and l != 4 - n) return true;
	return false;
}

char chr[Ma][Ma];

inline string gao(int a, int b) {
	string s;
	int lx = wd[a].x, ly = wd[a].y, rx = wd[b].x, ry = wd[b].y;
	
	for (int i = lx; (lx < rx ? i <= rx : i >= rx); lx < rx ? i++ : i--) {
		for (int j = ly; ly < ry ? j <= ry : j >= ry; ly < ry ? j++ : j--)
			if (chr[j][i] != a + 'A' and chr[j][i] != b + 'A') {
			if (check(wd[a], wd[b], wd[chr[j][i] - 'A'])) s += chr[j][i];
		}
	}	

	return s;
}

void init() {
	for (int i = 0; i < 26; i++)
		chr[wd[i].y][wd[i].x] = char('A' + i);

	for (int i = 0; i < 26; i++) 
		for (int j = i + 1; j < 26; j++) {
			string s = gao(i, j);
			path[i][j] = s;
			reverse(seg(s));
			path[j][i] = s;
		}
}

string calc(string s) {
	int len = s.length();
	string t; t += s[0];
	for (int i = 1; i < len; i++)
		t += path[s[i - 1] - 'A'][s[i] - 'A'] + s[i];
	return t;
}

bool check(const string a, const string b) {
	int len = b.length();
	int cnt = 0;
	for (const auto& i : a) {
		if (i == b[cnt]) ++cnt;
		if (cnt == len) break;
	}
	return cnt == len;
}

signed main() {
	#if SYNC==0
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
	for (char t = 'A'; t <= 'Z'; t++)
		wd[t - 'A'] = getp(t);
	init();
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		s = calc(s);
		//cerr << s << endl;
		bool out = false;
		for (int i = 0; i < n; i++) {
			string t; cin >> t;
			if (!out and check(s, t)) out = true, cout << t << endl;
		}
		if (!out) cout << "NO SOLUTION" << endl;
	}
    
    return 0;
}
