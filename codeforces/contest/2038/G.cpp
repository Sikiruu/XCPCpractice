#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int ask(const string &s) {
    cout << 1 << " " << s << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int answer(int i, int c) {
    cout << 0 << " " << i << " " << c << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void solve() {
    int n, n1, n01, n11, status;
    cin >> n;
    n1 = ask("1");
    n01 = ask("01");
    n11 = ask("11");
    status = answer(1, n1 == n01 + n11 ? 0 : 1);
    if (status == -1) {
        exit(0);
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
