#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
    int n, a, b, ans = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i != 0) {
            if (b - a != 5 && b - a != 7 && b - a != -5 && b - a != -7) {
                ans = 0;
            }
        }
        swap(a, b);
    }
    cout << (ans ? "YES" : "NO") << "\n";
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