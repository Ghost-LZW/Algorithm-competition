/*************************************************************************
    > File Name: f.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sun Jul 12 12:09:50 2020
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'

string mul(const string& t, int res, int la) {
	string now;
	int rt = res / la;
	for (int i = 0; i < rt; i++)
		now += t;
	return now;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	while (cin >> a >> b) {
		ll la = a.length();
		ll lb = b.length();
		int ck = 1;
		if (la > lb) swap(la, lb), swap(a, b), ck = -1;
		ll c = la * lb / __gcd(la, lb);
		bool can = false;
		int sta = 0;
		if (a[0] == b[0])
			can = (a == string(la, a[0]) and b == string(lb, b[0]));

		if (!can)
		for (int i = 0; sta == 0 and i < c; i++) {
			if (a[i % la] > b[i % lb]) sta = 1;
			else if (a[i % la] < b[i % lb]) sta = -1;
		}
		if (sta == ck) cout << '>' << endl;
		else if (sta == 0) cout << '=' << endl;
		else cout << '<' << endl;
	}
	
	return 0;
}
