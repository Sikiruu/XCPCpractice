#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
const int N = 100005;
vector<int> num_factors(N, 0);

void solve() {
    int n, m;
    set<int> s;
    vector<int> vec;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (auto t : s) {
        vec.push_back(t);
    }
    // cout << num_factors[7];

    vector<int> ans;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (m - num_factors[i] - 1 >= 0) {
            ans.push_back(vec[m - num_factors[i] - 1]);
        } else {
            flag = false;
            break;;
        }
    }

    if (flag == true) {
        for (auto t : ans) {
            cout << t << " ";
        }
    } else {
        cout << -1;
    }
    cout << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 2; i <= N - 1; ++i) {
        if (num_factors[i] == 0) {
            for (int j = i; j <= N - 1; j += i) {
                int t = j, cnt = 0;
                while (t % i == 0) {
                    ++cnt;
                    t /= i;
                }
                num_factors[j] += cnt;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
