#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100005;
ll a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i + i < n - 1; ++i) {
        ll diff = a[i] - a[n - i - 1];
        diff = diff < 0 ? -diff : diff;
        ans = __gcd(ans, diff);
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
