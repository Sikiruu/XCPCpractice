#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 200005;
ll sum_of_price[N] = {0};

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        sum_of_price[i] = 0;
    }
    for (int i = 0; i < k; ++i) {
        int b, p;
        cin >> b >> p;
        sum_of_price[b] += p;
    }
    sort(sum_of_price + 1, sum_of_price + 1 + k);
    ll ans = 0;
    for (int i = 0; i < n && k - i > 0; ++i) {
        ans += sum_of_price[k - i];
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
