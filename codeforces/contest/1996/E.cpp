#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll Z = 1000000007;

void solve() {
    string s;
    cin >> s;
    s.insert(s.begin(), '.');

    ll ans = 0, n = s.length() - 1;
    map<ll, ll> mp; // mp[i] = j: for su, prefix sum = j
    vector<ll> su(s.length(), 0);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            su[i] = su[i - 1] + 1;
        } else {
            su[i] = su[i - 1] - 1;
        }
    }

    mp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        // su[x] == su[y] -> [x + 1, y]
        ans = (ans + mp[su[i]] * (n - i + 1)) % Z;
        mp[su[i]] = (mp[su[i]] + i + 1) % Z;
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
