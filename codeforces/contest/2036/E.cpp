#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll intersection(pll a, pll b) {
    ll left = max(a.first, b.first);
    ll right = min(a.second, b.second);
    if (left > right || a.first == -1 || b.first == -1) {
        return {-1, -1};
    }
    return {left, right};
}

void solve(vector<vector<ll>> &a, ll n, ll k) {
    ll m;
    pll range = make_pair(1, n);
    cin >> m;
    for (ll i = 1; i <= m; ++i) {
        ll r, c;
        char opt;
        cin >> r >> opt >> c;

        pll current;
        if (opt == '>') {
            auto t = upper_bound(a[r].begin() + 1, a[r].end(), c);
            if (t != a[r].end()) {
                current = make_pair(t - a[r].begin(), n);
            } else {
                current = make_pair(-1, -1);
            }
        } else {
            auto t = lower_bound(a[r].begin() + 1, a[r].end(), c);
            if (t != a[r].begin() + 1) {
                current = make_pair(1, t - a[r].begin() - 1);
            } else {
                current = make_pair(-1, -1);
            }
        }
        range = intersection(range, current);
    }
    cout << range.first << "\n";
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, k, q;
    cin >> n >> k >> q;
    vector<vector<ll>> a(k + 1, vector<ll>(n + 1, 0));
    
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= k; ++j) {
            cin >> a[j][i];
            a[j][i] = (a[j][i] | a[j][i - 1]);
            // cout << a[j][i] << " ";
        }
        // cout << "\n";
    }

    while (q--) {
        solve(a, n, k);
    }

    return 0;
}
