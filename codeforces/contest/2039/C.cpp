#include <iostream>
using namespace std;

typedef long long ll;

void easy() {
    int x, ans = 0;
    ll m;
    cin >> x >> m;
    for (int i = 1; i < 3 * x && i <= m; ++i) {
        int t = x ^ i;
        if (t != 0) {
            ans += (x % t == 0 || i % t == 0);
        }
    }
    cout << ans << "\n";
}

void hard() {
    ll x, m;
    cin >> x >> m;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        // easy();
        hard();
    }

    return 0;
}
