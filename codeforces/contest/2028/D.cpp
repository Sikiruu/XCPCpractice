#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1000006;

vector<pair<int, char> > to[N], ans;
bool vis[N];
pair<int, int> p[4][N];
// int p[4][N];
char names[] = ".qkj";
int n;
int st[N], top = 0;

void add(int u, int v, char name) { // u -> v
    to[u].push_back(make_pair(v, name));
}

bool dfs(int now) {
    vis[now] = true;
    if (now == n) {
        return true;
    }
    for (auto [t, name] : to[now]) {
        if (vis[t] == false) {
            bool status = dfs(t);
            if (status == true) {
                ans.push_back(make_pair(t, name));
                return true;
            }
        }
    }
    return false;
}



void solve() {
    cin >> n;
    for (int i = 1; i <= 3; ++i) {
        char name = names[i];

        for (int j = 1; j <= n; ++j) {
            cin >> p[i][j].first;
            p[i][j].second = j;
        }
        
        sort(p[i] + 1, p[i] + n + 1);

        top = 0;
        for (int j = 1; j <= n; ++j) {
            int &val = p[i][j].second;
            while (st[top] > val) {
                add(val, st[top], name);
                --top;
            }
            st[++top] = val;
        }
/*

        for (int j = 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (p[i][j].second > p[i][k].second) {
                    add(p[i][k].second, p[i][j].second, name);
                }
            }
        }

    }
*/
    dfs(1);

    if (ans.size() > 0) {
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i].second << " " << ans[i].first << "\n";
        }
    } else {
        cout << "NO" << "\n";
    }

    ans.clear();
    for (int i = 1; i <= 3 * n + 10; ++i) {
        vis[i] = false;
        to[i].clear();
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
