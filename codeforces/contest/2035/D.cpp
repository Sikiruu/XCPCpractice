#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll N = 200005, Z = (ll)1e9+7;
ll a[N], su[N], su_base[N], su_pow[N], base[N];

ll fpow(ll x, ll y) { // x ^ y
    ll t = 1, ret = 1;
    while (y != 0) {
        t = t * x % Z;
        if (y % 2 == 1) {
            ret *= t;
        }
        y /= 2;
    }
    return ret;
}

ll prefix(int n) {
    if (n == 40) {
        n = 40;
    }
    ll ans = su[n], mx = a[n], p = -1;
    for (int i = n - 1; i >= 1; --i) {
        if (base[i] < mx) {
            ll mxx = mx * a[i] / base[i];
            ans = (ans - (a[i] - base[i]) + (mxx - mx) + Z) % Z;
            mx = mxx;
        } else {
            mx = a[i];
        }
        if (mx > Z) {
            p = i;
            break;
        }
    }

    if (p > 1) {
        --p;
        ll mxx = mx * fpow(2, su_pow[p]);
        ans = (ans - (su[p] - su_base[p]) + (mxx - mx) + Z) % Z;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        su[i] = (su[i - 1] + a[i]) % Z;
        ll t = a[i], cnt = 0;
        while (t % 2 == 0) {
            t /= 2;
            ++cnt;
        }
        su_base[i] = (su_base[i - 1] + t) % Z;
        su_pow[i] = su_pow[i - 1] + cnt;
        base[i] = t;
    }

    for (int i = 1; i <= n; ++i) {
        cout << prefix(i) << " ";
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
