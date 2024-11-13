#include <iostream>

using namespace std;

typedef long long ll;
const int N = 100005;

ll dp[N][3], b[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        dp[i][1] = dp[i][2] = dp[i][3] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = max(dp[i - 1][1] - 1, b[i]);
        if (dp[i - 1][1] != 0) {
            dp[i][2] = max(dp[i - 1][2] - 1, b[i] + dp[i - 1][1]);
        }
        if (dp[i - 1][2] != 0) {
            dp[i][3] = dp[i - 1][2] + b[i] - 1;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i][3]);
    }
    cout << ans - 1 << "\n";
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
