#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1000006;

int a[N];
bool impossible[N];

void solve() {
    int n;
    cin >> n;
    if (impossible[n] == true) {
        cout << "impossible" << "\n";
        return ;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    for (int i = 4; i < N; i += 4) {
        impossible[i] = true;
        swap(a[i], a[i - 1]);
    }


    impossible[1] = true;
    swap(a[0], a[1]);

    // for (int i = 0; i <= 12; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    // int t = 0;
    // for (int i = 1; i < N; ++i) {
    //     t ^= a[i - 1];
    //     if (t == 0 && impossible[i] == false) {
    //         cout << i << "\n";
    //         break;
    //     }
    // }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
