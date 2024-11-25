#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
    int n, n18, n21, n25, ans = 0;
    cin >> n;
    n18 = n21 = n25 = n;
    
    if (n == 1) {
        cout << 2 << "\n";
        return;
    }

    ans = n21 / 2;
    n18 -= n21 / 2;
    n21 -= n21 / 2 * 2;
    if (n21 == 1) {
        ++ans;
        n18 -= 2;
        --n21;
    }

    ans += n18 / 3;
    n18 -= n18 / 3 * 3;
    
    ans += n25 / 2;
    n25 -= n25 / 2 * 2;

    if (n25 == 1 && n18 == 2) {
        ans += 2;
    } else if (n25 == 1 && n18 <= 1) {
        ++ans;
    } else if (n25 == 0 && n18 != 0) {
        ++ans;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
