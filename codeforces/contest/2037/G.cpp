#include <iostream>
#include <vector>

using namespace std; 
typedef long long ll;

const ll A = 1000006, P = 998244353;
vector<ll> pri;
bool not_prime[A];
ll dp[A];

vector<ll> breakdown(ll x) {
    vector<ll> result;
    if (not_prime[x] == false) {
        result.push_back(x);
        return result;
    }
    for (auto i : pri) {
        if (x == 1) {
            break;
        } else if (not_prime[x] == false) {
            result.push_back(x);
            break;
        }
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            result.push_back(i);
        }
    }
    return result;
}

vector<pair<ll, ll> > special_breakdown(ll x) {
    vector<pair<ll, ll> > result;
    vector<ll> factors = breakdown(x);
    for (ll i = 1; i < (1 << factors.size()); ++i) {
        ll tt = 1, ii = i, cnt = 0, cnt2 = 0;
        while (ii != 0) {
            if (ii % 2 == 1) {
                tt *= factors[cnt];
                ++cnt2;
            }
            ++cnt;
            ii /= 2;
        }
        result.push_back(make_pair(tt, cnt2));
    }
    return result;
}

void help(ll val, vector<pair<ll, ll> > &factors) {
    for (auto [t, cnt] : factors) {
        dp[t] += val;
        dp[t] %= P;
    }
}

ll update(ll x) {
    vector<pair<ll, ll> > factors = special_breakdown(x);
    ll val = 0;
    for (auto [t, cnt] : factors) {
        val += cnt % 2 == 1 ? dp[t] : -dp[t] + P;
        val %= P;
    }
    help(val, factors);
    return val;
}

void solve() {
    for (ll i = 2; i <= A - 6; ++i) {
        if (!not_prime[i]) {
            pri.push_back(i);
        }
        for (ll pri_j : pri) {
            if (i * pri_j > A - 6) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) break;
        }
    }
    not_prime[1] = true;

    ll n, a;
    cin >> n >> a;

    vector<pair<ll, ll> > factor_a1 = special_breakdown(a);
    help(1, factor_a1);

    for (ll i = 2; i <= n - 1; ++i) {
        cin >> a;
        update(a);
        // cout << update(a[i]) << " " << a[i];
        // cout << " " << dp[2] << " " << dp[3] << " " << dp[6] << "\n";
    }

    cin >> a;
    cout << update(a) << "\n";
    // cout << update(a[n]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
