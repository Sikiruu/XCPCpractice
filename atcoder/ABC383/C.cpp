#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1300, INF = 19260817;
char mp[N][N];
// vector<vector<bool>> vis(6, vector<bool>(6));
int timestep[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m, d, ans = 0;


void bfs(int x, int y) {
    queue<pair<int, pair<int, int>>> q;
    
    q.push({d, {x, y}});
    timestep[x][y] = d;
    ++ans;

    while (q.empty() == false) {
        int nx = q.front().second.first, ny = q.front().second.second, left = q.front().first;
        q.pop();

        if (left == 0) {
            break;
        }

        for (int i = 0; i <4; ++i) {
            int tx = nx + dx[i], ty = ny + dy[i];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && mp[tx][ty] == '.' && timestep[tx][ty] < left - 1) {
                q.push({left - 1, {tx, ty}});
                if (timestep[tx][ty] == -1) {
                    ++ans;
                }
                timestep[tx][ty] = left - 1;
            }
        }
    }
}

void solve() {
    cin >> n >> m >> d;

    for (int i = 1; i <= n; ++i) {
        scanf("%s", mp[i] + 1);
        for (int j = 0; j <= m; ++j) {
            timestep[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == 'H') {
                bfs(i, j);
            }
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << (int)timestep[i][j];
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
