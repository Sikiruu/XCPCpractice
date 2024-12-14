#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 250000;
pair<int, pair<int, int>> edges[N]; // {val, {from, to}}
pair<int, pair<int, int>> nodes[N]; // {fa, {#A, #B}}

int find_father(int x) {
    if (nodes[x].first == x) {
        return x;
    }
    return nodes[x].first = find_father(nodes[x].first);
}

int merge_nodes(int x, int y) {
    int fx = find_father(x), fy = find_father(y);
    if (x == y) {
        return 0;
    }
    nodes[fy].first = fx;
    nodes[fx].second.first += nodes[fy].second.first;
    nodes[fx].second.second += nodes[fy].second.second;
    int ret = min(nodes[fx].second.first, nodes[fx].second.second);
    if (nodes[fx].second.first > nodes[fx].second.second) {
        nodes[fx].second.first -= nodes[fx].second.second;
        nodes[fx].second.second = 0;
    } else {
        nodes[fx].second.second -= nodes[fx].second.first;
        nodes[fx].second.first = 0;
    }
    return ret;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i) {
        int u, v, val;
        cin >> u >> v >> val;
        edges[i] = {val, {u, v}};
    }
    sort(edges + 1, edges + m + 1);

    for (int i = 1; i <= n; ++i) {
        nodes[i].first = i;
    }
    for (int i = 1; i <= k; ++i) {
        int t;
        cin >> t;
        nodes[t].second.first += 1;
    }
    for (int i = 1; i <= k; ++i) {
        int t;
        cin >> t;
        nodes[t].second.second += 1;
    }
    
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        int u = edges[i].second.first, v = edges[i].second.second, val = edges[i].first;
        // cout << u << find_father(u) << v << find_father(v) << "\n";
        ll t = merge_nodes(u, v);
        ans += 1LL * val * t;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
