#include <iostream>

using namespace std;

typedef long long ll;
const int N = 200005;

ll a[N];

ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans = 0, follow = a[n];
    for (int i = n - 1; i >= 1; --i) {
        ll pieces = ceilDiv(a[i], follow);
        // cout << follow << " ";
        follow = a[i] / pieces;
        ans += pieces - 1;
    }
    cout << ans << "\n";
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
