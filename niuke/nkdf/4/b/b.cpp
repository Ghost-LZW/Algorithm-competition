/*************************************************************************
    > File Name: b.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jul 18 21:12:41 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 得到牛牛能够凑到的最大的数字
     * @param n int整型 牛牛能够承受的价格
     * @param a int整型vector 1-9这九个数字的价格数组
     * @return string字符串
     */
	static bool cmp(string a, string b) {
		sort(a.begin(), a.end(), greater<char>()); sort(b.begin(), b.end(), greater<char>());
		if (a.length() != b.length()) return a.length() > b.length();
		else return a > b;
	}

    string solve(int n, vector<int> a) {
		string dp[n + 1];
		for (int i = 0; i < 9; i++)
			for (int j = a[i]; j <= n; j++) {
				if (cmp(dp[j - a[i]] + char('1' + i), dp[j]))
					dp[j] = dp[j - a[i]] + char('1' + i);
			}
		sort(dp, dp + n + 1, cmp);
		sort(dp[0].begin(), dp[0].end(), greater<char>());
		
		return dp[0];
    }
}ss;

int main() {
	cerr << ss.solve(5,{5,4,3,2,1,2,3,4,5}) << endl;
	
	return 0;
}
