/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jul 18 21:02:45 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 处理函数，返回在所有分法中，蛋糕数量最少的盘子中分到最多的蛋糕数量
     * @param n int整型 n个盘子
     * @param a int整型 a蛋糕数量
     * @param b int整型 b蛋糕数量
     * @return int整型
     */
	bool check(int res, int n, int a, int b) {
		int cnt = 0;
		while (a >= res) ++cnt, a -= res;
		while (b >= res) ++cnt, b -= res;
		return cnt >= n;
	}

    int solve(int n, int a, int b) {
        int l = 1, r = min(a, b) + 1;
		while (r - l > 1) {
			int mid (l + (r - l) / 2);
			if (check(mid, n, a, b)) l = mid;
			else r = mid;
		}
		return l;
    }
} ss;

int main(){
	cerr << ss.solve(4, 7, 10) << endl;

	return 0;
}
