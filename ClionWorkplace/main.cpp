/*************************************************************************
    > File Name: g.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com
    > Created Time: Thu Nov 19 19:45:22 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define rep(i, x) for(int i=0;i<(x);++i)
#define seg(x) (x).begin(),(x).end()

const int Ma = 3e3;
int f[Ma]; int ans;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch=  getchar();
    }
    return x * f;
}

int n;

void dfs(int u, int res, int pre) {
    if (u == n) {
        ans = max(ans, pre - f[1] + f[res + 1]);
        return ;
    }
    for (int i = 0; i <= min(res, n - 2) and i <= res; i++) {
        dfs(u + 1, res - i, pre - f[1] + f[i + 1]);
    }
}

int main() {
	int T = read();
	while (T--) {
		n = read();
		rep (i, n - 1) f[i + 1] = read();
        ans = 0;
        dfs(1, n - 2, f[1] * n);
        printf("%d\n", ans);
	}

	return 0;
}
