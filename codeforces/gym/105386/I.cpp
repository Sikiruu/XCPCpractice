#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 500005;
char s[N];
int segment[N];

void solve() {
    scanf("%s", s + 1);
    
    int start = 1, cnt = 0, n = strlen(s + 1);
    for (int i = 2; i <= n + 1; ++i) {
        if (s[i] != s[i - 1]) {
            ++cnt;
            segment[cnt] = i - start;
            start = i;
        }
    }

    // for (int i = 1; i <= cnt; ++i) {
    //     cout << segment[i] << " ";
    // }
    // cout << "\n";
    
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        ans += segment[i] / 2;
    }

    if (cnt != 1) {
        if (s[1] == s[n]) {
            int now = 1;
            bool has_even = false;
            for (int i = 2; i <= cnt - 1; ++i) {
                if (segment[i] % 2 == 0) {
                    has_even = true;
                    break;
                }
            }
            if (segment[1] % 2 == 0 && segment[cnt] % 2 == 0) {
                --ans;
            } else if ((segment[1] + segment[cnt]) % 2 == 1 && has_even) {
                --ans;
            }
        } else {
            for (int i = 1; i <= cnt; ++i) {
                if (segment[i] % 2 == 0) {
                    --ans;
                    break;
                }
            }
        }
    }

    cout << ans << "\n";

}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
