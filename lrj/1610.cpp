#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int n;
    while (cin >> n and n) {
        vector<string> s(n);
        for (auto& i : s) cin >> i;
        sort(s.begin(), s.end());
        string l = s[n / 2 - 1], r = s[n / 2];
        int len = l.length(), lr = r.length();
        // cerr << l << ' ' << r << endl;
        string ans;
        for (int i = 0; i < len; ++i) {
            if (i < lr and l[i] == r[i]) ans += l[i];
            else {
                if (i == len - 1) ans += l[i];
                else if (l[i] != 'Z' and not (i == lr - 1 and r[i] - l[i] == 1)) {
                    ans += char(l[i] + 1);
                    break;
                } else ans += l[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
