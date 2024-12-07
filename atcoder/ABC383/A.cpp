#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    int n, tt = 1, remain = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t, v;
        cin >> t >> v;
        while (tt <= t) {
            ++tt;
            if (remain > 0) {
                --remain;
            }
        }
        remain += v;
    }
    cout << remain << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
