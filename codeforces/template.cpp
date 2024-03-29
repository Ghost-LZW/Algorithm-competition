/*************************************************************************
  > File Name: solve.cpp
  > Author: $%U%$
  > Mail: lanzongwei@gmail.com
  > Created Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
 ************************************************************************/

#define GOODOJ
#define SYNC 0
#define MUL 1

#ifdef GOODOJ
#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <random>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#else
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#endif
using namespace std;

#define endl '\n'
#define fep(i, b, e) for (int i = (b), i##_ = (e); i < i##_; ++i)
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; ++i)
#define rap(i, x) for (auto &i : (x))
#define seg(t) (t).begin(), (t).end()
#define rseg(t) (t).rbegin(), (t).rend()
#define sz(x) (int)(x).size()
#define eb emplace_back
#define ep emplace
#define mkp make_pair
#define mkt make_tuple
#define qxx(i, x) for (int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x)) & (x))
#define RE register
#define getchar() getchar_unlocked()
#ifdef DEBUG
void err(istream_iterator<string>) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ';
	err(++it, args...);
}
#define debug(args...)                                                         \
{                                                                            \
	string _s = #args;                                                         \
	replace(seg(_s), ',', ' ');                                                \
	cerr << "DEBUG:";                                                          \
	istringstream it(_s);                                                      \
	err(istream_iterator<string>(it), args);                                   \
	cerr << endl;                                                              \
}
#else
#define debug(...)
#endif

template <typename T> inline bool cmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}
template <typename T> inline bool cmin(T &a, const T &b) {
	return a > b ? a = b, 1 : 0;
}

#ifdef GOODOJ
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef __gnu_pbds::priority_queue<int> pq;
#endif
using str = std::string;
using vi = vector<int>;
using ll = int64_t;
using db = double;
using pa = pair<int, int>;

template <typename T>
ostream &operator<<(ostream &out, const std::vector<T> &v) {
	for (auto &i : v)
		out << i << ' ';
	return out;
}

template <typename T, size_t size>
ostream &operator<<(ostream &out, const std::array<T, size> &a) {
	out << '[';
	for (auto &i : a)
		out << i << ' ';
	out << ']';
	return out;
}

const double P = acos(-1.0), eps = 1e-9;
struct point {
	db x, y;
};
inline int sign(db a) { return a < -eps ? -1 : a > eps; }
#define dot(p1, p2, p3)                                                        \
	((p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y))
#define cross(p1, p2, p3)                                                      \
	((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

#ifdef GOODOJ
constexpr
#else
const
#endif
int Ma = 1e6,
		inf = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
	;
}

signed main() {
#if SYNC == 0
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
#endif
#if MUL == 0
	solve();
#else
	int t = 1;
	cin >> t;
	for (int qq = 0; qq < t; ++qq)
		solve();
#endif

	return 0;
}

