#include <iostream>
using namespace std;

typedef long long ll;

void easy() {
    int x, ans = 0;
    ll m;
    cin >> x >> m;
    for (int i = 1; i < 3 * x && i <= m; ++i) {
        int t = x ^ i;
        if (t != 0) {
            ans += (x % t == 0 || i % t == 0);
        }
    }
    cout << ans << "\n";
}

void hard() {
    int x; ll m; cin >> x >> m;

    // divisible by x
    ll p = m - m % x;
    ll ans = p / x - (x < p);
    if ((x ^ p) >= 1 and (x ^ p) <= m) ++ans;
    p += x;
    if ((x ^ p) >= 1 and (x ^ p) <= m) ++ans;

    // divisibly by y
    for (int y = 1; y <= min(1LL * x, m); y++) {
        ll cur = x ^ y;
        if (cur % y == 0) {
            ++ans;
        }
    }

    // divisible by both
    if (x <= m) {
        --ans;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        // easy();
        hard();
    }

    return 0;
}
