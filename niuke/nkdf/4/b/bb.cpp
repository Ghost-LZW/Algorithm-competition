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
    string solve(int n, vector<int> a) {
        int r[9];
        for (int i = 0; i < 9; i++) r[i] = i;
        sort(r, r + 9, [&](int i, int j) {
                if (a[i] != a[j]) return a[i] < a[j];
                else return i < j;
            });
        vector<int> res;
        int ind = 0, real = 0;
        while (ind + 1 < 9 and a[r[ind]] == a[r[ind + 1]]) {
            if (r[ind + 1] > r[real]) real = ind + 1;
            ++ind;
        }
        while (n >= a[r[real]]) {
            n -= a[r[real]], res.emplace_back(r[real] + 1);
        }
        sort(res.begin(), res.end(), greater<int>() );
        string ans;
        for (const auto& i : res) ans += char('0' + i);
        if (ans.length() == 0) ans = "-1";
        return ans;
    }
} ss;

int main() {
	cerr << ss.solve(5,{5,4,3,2,1,2,3,4,5}) << endl;
	
	return 0;
}
