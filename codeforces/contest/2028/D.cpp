#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 200005;

int p[4][N];
pair<char, int> ans[N]; // 找谁换到了什么: {谁, 什么}
vector<pair<char, int>> res;
bool vis[N];
char names[] = ".qkj";

void solve() {
    int n;
    cin >> n;
    for (int j = 1; j <= 3; ++j) {
        for (int i = 1; i <= n; ++i) {
            cin >> p[j][i];
        }
    }

    pair<int, int> min_p[4];
    for (int j = 1; j <= 3; ++j) {
        min_p[j].first = p[j][n];
        min_p[j].second = n;
    }
    vis[n] = true;

    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= 3; ++j) {
            char name = names[j];
            if (p[j][i] > min_p[j].first) {
                ans[i].first = name;
                ans[i].second = min_p[j].second;
                vis[i] = true;
            }
        }
        if (vis[i]) {
            for (int j = 1; j <= 3; ++j) {
                if (p[j][i] < min_p[j].first) {
                    min_p[j].first = p[j][i];
                    min_p[j].second = i;
                }
            }
        }
    }

    if (vis[1] == false) {
        cout << "NO" << "\n";
    } else {
        int x = 1;
        while (x != n) {
            res.push_back(make_pair(ans[x].first, ans[x].second));
            x = ans[x].second;
        }
        cout << "YES" << "\n";
        cout << res.size() << "\n";
        for (auto [name, t] : res) {
            cout << name << " " << t << "\n";
        }
    }

    res.clear();
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
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
