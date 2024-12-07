#include <iostream>
#include <vector>
// #include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    int n;
    cin >> n;

    int mx = -1, mn = (int)1e9;
    vector<int> left_max(n + 1), right_min(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        left_max[i] = mx;
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i = n; i >= 1; --i) {
        right_min[i] = mn;
        mn = min(mn, a[i]);
    }

    vector<int> ans(n + 1);
    ans[n] = max(a[n], left_max[n]);
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] > a[i + 1] || (a[i] > right_min[i] && left_max[i] > right_min[i] && left_max[i] > a[i + 1]) || (left_max[i] > a[i] && left_max[i] > a[i + 1]) || (left_max[i] > a[i] && left_max[i] > right_min[i] && a[i + 1] > right_min[i]) || (a[i] > right_min[i] && a[i + 1] > right_min[i])) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = max(a[i], left_max[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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