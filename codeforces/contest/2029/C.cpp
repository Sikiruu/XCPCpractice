#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll N = 300015;
int a[N], dp[N][2][2]; // dp[i][0/1][0/1] means at position i, wether start or end block

int change(int ai, int val) {
    if (ai > val) {
        ++val;
    } else if (ai < val) {
        --val;
    }
    return val;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    dp[0][0][0] = 0;
    dp[1][1][0] = 0;
    dp[1][1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = change(a[i], dp[i - 1][0][0]);
        if (i >= 2) {
            dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]); // skip
            dp[i][1][1] = max(change(a[i], dp[i - 1][1][0]), change(a[i], dp[i - 1][1][1]));
        }
        // cout << dp[i][0][0] << " " << dp[i][1][0] << " " << dp[i][1][1] << "\n";
    }

    cout << max(dp[n][1][0], dp[n][1][1]) << "\n";
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
