#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int ask(int l, int r) {
    cout << "?" << " " << l << " " << r << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void answer(const string &s, int n) {
    cout << "!" << " ";
    for (int i = 1; i <= n; ++i) {
        cout << s[i];
    }
    cout << "\n";
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    vector<int> num(n + 11);
    string ans(n + 11, '0');

    num[n] = ask(1, n);

    if (num[n] == 0) {
        cout << "!" << " " << "IMPOSSIBLE" << "\n";
        cout.flush();
        return ;
    }

    for (int i = 2; i <= n - 1; ++i) {
        num[i] = ask(1, i);
    }

    int nz = 2;
    while (num[nz] == 0) {
        ++nz;
    }

    // 11100001010100 -> nz = 8; num[nz] = 4; #1 = nz - num[nz] - 1 = 3; #0 = 4;
    for (int i = 1; i <= nz - num[nz] - 1; ++i) {
        ans[i] = '1';
    }

    for (; nz <= n; ++nz) {
        ans[nz] = '0' + (num[nz] != num[nz - 1]);
    }

    answer(ans, n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
