#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int md(int x, int y, int i, int j) {
    return abs(x - i) +  abs(y - j);
}

void solve() {
    const char TABLE = '#', FLOOR = '.';


    int n, m, d;
    cin >> n >> m >> d;
    
    string s[13];
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i].insert(s[i].begin(), ' ');
    }

    int max_ans = 0;
    for (int x1 = 1; x1 <= n; ++x1) {
        for (int y1 = 1; y1 <= m; ++y1) {
            if (s[x1][y1] != FLOOR) {
                continue;
            }

            for (int x2 = 1; x2 <= n; ++x2) {
                for (int y2 = 1; y2 <= m; ++y2) {
                    if (s[x2][y2] != FLOOR || (x2 == x1 && y2 == y1)) {
                        continue;
                    }

                    int ans = 0;
                    for (int i = 1; i <= n; ++i) {
                        for (int j =  1; j <= m; ++j) {
                            if (s[i][j] == FLOOR && (md(x1, y1, i, j) <= d || md(x2, y2, i, j) <= d)) {
                                ++ans;
                            }
                        }
                    }

                    max_ans = max(ans, max_ans);
                }
            }
        }
    }

    cout << max_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
