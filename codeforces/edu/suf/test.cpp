#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 50000 + 5, inf = 0x7fffffff;
int len, tk;
int Rank[maxn], tmp[maxn];
int S[maxn];
int sa[maxn], lcp[maxn];

bool compare_sa(int i, int j) {
    if (Rank[i] != Rank[j])    return Rank[i] < Rank[j];
    else {
        int ri = i + tk <= len ? Rank[i + tk] : -1;
        int rj = j + tk <= len ? Rank[j + tk] : -1;
        return ri < rj;
    }
}

void construct_sa() {
    for (int i = 0; i <= len; i++) {
        sa[i] = i;
        Rank[i] = i < len ? S[i] : -1;
    }

    for (tk = 1; tk <= len; tk *= 2) {
        sort(sa, sa + len + 1, compare_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= len; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= len; i++) {
            Rank[i] = tmp[i];
        }
    }
}

void construct_lcp() {
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < len; i++) {
        int j = sa[Rank[i] - 1];

        if (h > 0)    h--;
        for (; j + h < len && i + h < len; h++) {
            if (S[j + h] != S[i + h])    break;
        }
        lcp[Rank[i] - 1] = h;
    }
}

int RMQ[maxn];
int mm[maxn], best[20][maxn];
void initRMQ(int n) {
    mm[0] = -1;
    for (int i = 1; i <= n; i++)
        mm[i] = ((i&(i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
    for (int i = 1; i <= n; i++)    best[0][i] = i;
    for (int i = 1; i <= mm[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            int a = best[i - 1][j];
            int b = best[i - 1][j + (1 << (i - 1))];
            if (RMQ[a] < RMQ[b])    best[i][j] = a;
            else
            {
                best[i][j] = b;
            }
        }
    }
}
int askRMQ(int a, int b) {
    int t;
    t = mm[b - a + 1];
    b -= (1 << t) - 1;
    a = best[t][a];    b = best[t][b];
    return RMQ[a] < RMQ[b] ? a : b;
}
int find_lcp(int a, int b) {
    if (a>b) swap(a, b);
    return lcp[askRMQ(a, b - 1)];
}
int main()
{
    char inp[5];
    int H;
    scanf("%d", &H);
    while (H--) {
        scanf("%d", &len);
        for (int i = 0; i<len; i++) {
            scanf("%s", inp);
            if (inp[0] == 'a') S[i] = 0;
            else    S[i] = 1;
        }
        construct_sa();
        construct_lcp();
        for (int i = 1; i <= len; i++)    RMQ[i] = lcp[i];
        initRMQ(len);
        int ans = 1;
        for (int i = 1; i <= len; i++) {
            int ret = 0;
            for (int j = 0; j + i<len; j += i) {
                int r1 = Rank[j], r2 = Rank[j + i];
                int L = find_lcp(r1, r2);
                int temp = L / i + 1;
                int k = j - (i - L%i);
                if (k >= 0) {
                    temp = find_lcp(Rank[k], Rank[k + i]) / i + 1;
                }
                ret = max(ret, temp);
            }
            ans = max(ans, ret);
        }
        printf("%d\n", ans);
    }
    return 0;
}
