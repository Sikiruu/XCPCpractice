#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 102;
ll a[N];
vector<ll> remain;

void solve() {
    ll n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] % k != 0) {
            remain.push_back(k - (a[i] % k));
        }
        ans += a[i] / k;
    }

    ll m;
    cin >> m;

    sort(remain.begin(), remain.end());
    for (auto r : remain) {
        if (m >= r) {
            m -= r;
            ++ans;
        } else {
            break;
        }
    }

    cout << ans + m / k << "\n";

    remain.clear();
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
