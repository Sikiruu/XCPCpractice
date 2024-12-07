#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1000006;

vector<ll> pri;
bool not_prime[N + 6];

ll pow9(ll x) {
    return x * x * x * x * x * x * x * x;
}

void solve() {
    ll n, ans = 0;
    cin >> n;
    
    for (auto p : pri) {
        // cout << p << " " << pow9(p) << "\n";
        if (pow9(p) > n) {
            break;
        }
        ++ans;
    }

    for (int i = 0; pri[i] * pri[i] * pri[i + 1] * pri[i + 1] <= n; ++i) {
        for (int j = i + 1; pri[i] * pri[i] * pri[j] * pri[j] <= n; ++j) {
            // cout << pri[i] << " " << pri[j]  << " " << pri[i] * pri[i] * pri[j] * pri[j] << "\n";
            ++ans;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 2; i <= N; ++i) {
        if (!not_prime[i]) {
            pri.push_back(i);
        }
        for (ll pri_j : pri) {
            if (i * pri_j > N) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) break;
        }
    }

    solve();

    return 0;
}
