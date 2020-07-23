#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include <set>
#include <cstdio>
#include <cstring>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef unsigned int ull;

const int M = (int)2e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)998244353;
const double eps = 1e-8;

int n, m;
char s[M + 5], t[M + 5];
int cnts[M + 5][26];
int cntt[M + 5][26];
ull p[M + 5];
ull h[M + 5];
set <ull> vis;

ull cal(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool check(int l, int r)
{
    if(cntt[r][0] - cntt[l - 1][0] != cnts[n][0]) return 0;
    if(cntt[r][1] - cntt[l - 1][1] != cnts[n][1]) return 0;
    if(cntt[r][2] - cntt[l - 1][2] != cnts[n][2]) return 0;
    if(cntt[r][3] - cntt[l - 1][3] != cnts[n][3]) return 0;
    if(cntt[r][4] - cntt[l - 1][4] != cnts[n][4]) return 0;
    if(cntt[r][5] - cntt[l - 1][5] != cnts[n][5]) return 0;
    if(cntt[r][6] - cntt[l - 1][6] != cnts[n][6]) return 0;
    if(cntt[r][7] - cntt[l - 1][7] != cnts[n][7]) return 0;
    if(cntt[r][8] - cntt[l - 1][8] != cnts[n][8]) return 0;
    if(cntt[r][9] - cntt[l - 1][9] != cnts[n][9]) return 0;
    if(cntt[r][10] - cntt[l - 1][10] != cnts[n][10]) return 0;
    if(cntt[r][11] - cntt[l - 1][11] != cnts[n][11]) return 0;
    if(cntt[r][12] - cntt[l - 1][12] != cnts[n][12]) return 0;
    if(cntt[r][13] - cntt[l - 1][13] != cnts[n][13]) return 0;
    if(cntt[r][14] - cntt[l - 1][14] != cnts[n][14]) return 0;
    if(cntt[r][15] - cntt[l - 1][15] != cnts[n][15]) return 0;
    if(cntt[r][16] - cntt[l - 1][16] != cnts[n][16]) return 0;
    if(cntt[r][17] - cntt[l - 1][17] != cnts[n][17]) return 0;
    if(cntt[r][18] - cntt[l - 1][18] != cnts[n][18]) return 0;
    if(cntt[r][19] - cntt[l - 1][19] != cnts[n][19]) return 0;
    if(cntt[r][20] - cntt[l - 1][20] != cnts[n][20]) return 0;
    if(cntt[r][21] - cntt[l - 1][21] != cnts[n][21]) return 0;
    if(cntt[r][22] - cntt[l - 1][22] != cnts[n][22]) return 0;
    if(cntt[r][23] - cntt[l - 1][23] != cnts[n][23]) return 0;
    if(cntt[r][24] - cntt[l - 1][24] != cnts[n][24]) return 0;
    if(cntt[r][25] - cntt[l - 1][25] != cnts[n][25]) return 0;
    ull H = cal(l, r);
    if(!vis.count(H))
    {
        vis.insert(H);
        return 1;
    }
    return 0;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 1; i <= n; ++i)
    {
        cnts[i][0] = cnts[i - 1][0];
        cnts[i][1] = cnts[i - 1][1];
        cnts[i][2] = cnts[i - 1][2];
        cnts[i][3] = cnts[i - 1][3];
        cnts[i][4] = cnts[i - 1][4];
        cnts[i][5] = cnts[i - 1][5];
        cnts[i][6] = cnts[i - 1][6];
        cnts[i][7] = cnts[i - 1][7];
        cnts[i][8] = cnts[i - 1][8];
        cnts[i][9] = cnts[i - 1][9];
        cnts[i][10] = cnts[i - 1][10];
        cnts[i][11] = cnts[i - 1][11];
        cnts[i][12] = cnts[i - 1][12];
        cnts[i][13] = cnts[i - 1][13];
        cnts[i][14] = cnts[i - 1][14];
        cnts[i][15] = cnts[i - 1][15];
        cnts[i][16] = cnts[i - 1][16];
        cnts[i][17] = cnts[i - 1][17];
        cnts[i][18] = cnts[i - 1][18];
        cnts[i][19] = cnts[i - 1][19];
        cnts[i][20] = cnts[i - 1][20];
        cnts[i][21] = cnts[i - 1][21];
        cnts[i][22] = cnts[i - 1][22];
        cnts[i][23] = cnts[i - 1][23];
        cnts[i][24] = cnts[i - 1][24];
        cnts[i][25] = cnts[i - 1][25];
        ++cnts[i][s[i] - 'a'];
    }
    p[0] = 1;
    for(int i = 1; i <= m; ++i)
    {
        cntt[i][0] = cntt[i - 1][0];
        cntt[i][1] = cntt[i - 1][1];
        cntt[i][2] = cntt[i - 1][2];
        cntt[i][3] = cntt[i - 1][3];
        cntt[i][4] = cntt[i - 1][4];
        cntt[i][5] = cntt[i - 1][5];
        cntt[i][6] = cntt[i - 1][6];
        cntt[i][7] = cntt[i - 1][7];
        cntt[i][8] = cntt[i - 1][8];
        cntt[i][9] = cntt[i - 1][9];
        cntt[i][10] = cntt[i - 1][10];
        cntt[i][11] = cntt[i - 1][11];
        cntt[i][12] = cntt[i - 1][12];
        cntt[i][13] = cntt[i - 1][13];
        cntt[i][14] = cntt[i - 1][14];
        cntt[i][15] = cntt[i - 1][15];
        cntt[i][16] = cntt[i - 1][16];
        cntt[i][17] = cntt[i - 1][17];
        cntt[i][18] = cntt[i - 1][18];
        cntt[i][19] = cntt[i - 1][19];
        cntt[i][20] = cntt[i - 1][20];
        cntt[i][21] = cntt[i - 1][21];
        cntt[i][22] = cntt[i - 1][22];
        cntt[i][23] = cntt[i - 1][23];
        cntt[i][24] = cntt[i - 1][24];
        cntt[i][25] = cntt[i - 1][25];
        ++cntt[i][t[i] - 'a'];
        p[i] = p[i - 1] * 131;
        h[i] = h[i - 1] * 131 + t[i] - 'a' + 1;
    }
    int ans = 0;
    for(int i = 1; i + n - 1 <= m; ++i)
    {
        if(check(i, i + n - 1)) ++ans;
    }
    if(n > 1000) assert(ans <= 750);
    printf("%d\n", ans);
    return 0;
}

