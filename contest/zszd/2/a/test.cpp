#include <iostream>
#include <cstring>
using namespace std;

const int Ma = 1e5 + 100, inf = 0x3f3f3f3f, mod = 1e9 + 7;

bool vis[Ma];
typedef int ss[3];
static int val = sizeof(ss);

signed main() {
	ss i = {1, 2, 3}, j = {1, 2, 3};
   	cout << boolalpha << memcmp(i, j, val) << endl;	

    return 0;
}

