#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 500005;

vector<int> to[N];
int dep[N], max_dep[N], layers;
ll diff[N];

void dfs(int now, int fa) {
    max_dep[now] = dep[now] = dep[fa] + 1;
    layers = max(layers, dep[now]);
    for (auto t : to[now]) {
        if (t == fa) {
            continue;
        }
        dfs(t, now);
        max_dep[now] = max(max_dep[now], max_dep[t]);
    }
}

void solve() {
    int n;
    cin >> n;

    layers = 0;
    for (int i = 1; i <= n; ++i) {
        to[i].clear();
        diff[i] = dep[i] = max_dep[i] = 0;
    }

    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        --diff[max_dep[i] + 1];
        ++diff[dep[i]];
    }

    ll ans = n;
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        // cout << diff[i] << " ";
        ans = min(ans, n - diff[i]);
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