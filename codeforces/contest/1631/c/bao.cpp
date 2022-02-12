/*************************************************************************
	> File Name: solve.cpp
	> Author: baoliPass1e10
	> Mail: lanzongwei@gmail.com
	> Created Time: 2022-01-24 14:45:31
 ************************************************************************/

#define GOODOJ
#define SYNC 0
#define MUL 0

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

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 119 << 23 | 1;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}


#ifdef GOODOJ
constexpr
#else
const
#endif
int Ma = 1e6,
		inf = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
	for (auto n : {2, 4, 8, 16}) {
		vi id(n); iota(seg(id), 0);
		vi vis(n);
		do {
			int p = 0;
			for (int i = 0; i < n / 2; i++) {
				p += id[i] & id[n - 1 - i];
			}
			if (p < n) vis[p] = 1;
			if (p == 7 and n == 8) {
				debug(id);
				rap (i, id) debug(bitset<5>(i));
			}
		} while (next_permutation(seg(id)));
		debug(vis);
	}
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

