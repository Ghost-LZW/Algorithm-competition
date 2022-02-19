#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (int) 1e5;
const int N = (int) 1e5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-9;
const ll mod = (ll) 1e9 + 7;

double n, p1, v1, p2, v2;
typedef double db;

db ck(db t) {
    if (t < -eps) return inf;
    return t;
}

double cal() {
    db ans = max((n - p1) / v1, p2 / v2);
    ans = min(ans, min((n + n - p1) / v1, (p2 + n) / v2));
    ans = min(ans, min((p1 + n) / v1, (n - p2 + n) / v2));
    if (p1 / v1 >= (n - p2) / v2) {
        db t = p1 / v1 - (n - p2) / v2;
        db dis = v2 * t;
        if (dis >= n) {
            ans = min(ans, ck((n - p2) / v2 + n / v2));
        } else {
            ans = min(ans, ck(p1 / v1 + (n - dis) / (v1 + v2)));
        }
    } else {
        db t = (n - p2) / v2 - p1 / v1;
        db dis = v1 * t;
        if (dis >= n) {
            ans = min(ans, ck(p1 / v1 + n / v1));
        } else {
            ans = min(ans, ck((n - p2) / v2 + (n - dis) / (v1 + v2)));
        }
    }

    db t = (p2 - p1) / (v1 + v2);
    ans = min(ans, ck(t * 2 + max(p1 / v1, (n - p2) / v2)));

    db x = (v1 * p2 + v2 * p1 + v1 * n) / (2 * (v1 + v2));
    if (x >= p1 and x <= p2) {
        ans = min(ans, (2 * x - p1) / v1);
    }

    t = (n - p2) / v2;
    ans = min(ans, ck(t + ck((2 * n - p1 - v1 * t) / (v1 + 2 * v2))));

    t = p1 / v1;
    ans = min(ans, ck(t + ck((n + p2 - v2 * t) / (2 * v1 + v2))));

    ans = min(ans, max(p1 / v1, (n - p2 + n - p1) / v2));
    ans = min(ans, max((n - p2) / v2, (p1 + p2) / v1));

    assert(ans != inf);
    return ans + eps;
}

void work() {
    scanf("%lf %lf %lf %lf %lf", &n, &p1, &v1, &p2, &v2);
    if (p1 > p2) {
        swap(p1, p2);
        swap(v1, v2);
    }
    printf("%.10f\n", cal());
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
//    work();
    return 0;
}
