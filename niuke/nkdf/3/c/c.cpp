/*************************************************************************
    > File Name: c.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Thu Jul 16 23:19:19 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

/**
 * struct Point {
 *	int x;
 *	int y;
 * };
 */

struct Point {
	int x, y;
};

class Solution {
public:
    /**
     * 返回牛牛所能得到的字典序最小的排列
     * @param n int整型 
     * @param m int整型 
     * @param perm int整型vector 
     * @param Pair Point类vector 
     * @return int整型vector
     */
	static const int Ma = 1e5 + 100;
	int fa[Ma];
	vector<int> f[Ma];
	Solution() {
		for (int i = 1; i < Ma; i++) fa[i] = i;
	}

	int find(int x) {return fa[x] = fa[x] == x ? x : find(fa[x]);}
	void unio(int a, int b) {fa[find(b)] = find(a);}

    vector<int> solve(int n, int m, vector<int> perm, vector<Point> Pair) {
        for (const auto& i : Pair) unio(i.x, i.y);
		for (int i = 1; i <= n; i++) f[find(i)].emplace_back(i - 1);
		for (int i = 1; i <= n; i++) {
			vector<int> res;
			for (const auto& j : f[i]) res.emplace_back(perm[j]);
			sort(res.begin(), res.end());
			int k = 0;
			for (const auto& j : f[i]) perm[j] = res[k++];
		}
		return perm;
    }
} ss;

int main() {
	for (const auto& i :
		 ss.solve(5, 3, {5, 2, 3, 4, 1}, {{2, 4}, {1, 4}, {3, 4}}))
		cerr << i << ' ';
	
	return 0;
}
