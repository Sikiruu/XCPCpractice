#include <iostream>

using namespace std;

typedef long long ll;

ll ceildiv(ll a, ll b){
    if (a % b != 0) {
        return a / b + 1;
    } else {
        return a / b;
    }
}

void solve() {
    ll n, b, c;
    cin >> n >> b >> c; // ai = b(n - i) + c
    if (b == 0) {
        if (c >= n - 2) {
            if (c <= n - 1) {
                cout << n - 1 << "\n";
            } else {
                cout << n << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
    } else {
        if (c > n - 1) {
            cout << n << "\n";
        } else {
            ll u = n - 1, d = 0;
            ll uu = (u - c) / b + 1, dd = 1;
            cout << n - (uu - dd + 1) << "\n";
        }
    }
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
