#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> a;
vector<vector<ll>> dp;

ll solve(const int idx, const int r) {
    if (r < 0) return 0;
    if (r == 0) return 1;
    if (idx >= a.size()) return 0;

    ll &ans = dp[idx][r];
    if (ans != -1) return ans;


    int j = idx, rep = 0;
    while (j < a.size() && a[j] == a[idx]) {
        ++j, ++rep;
    }
    ll res = 0;
    for (int i = 0; i <= rep; ++i) {
        res += solve(j, r - i);
    }

    return ans = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    for (int tc = 1;; ++tc) {
        int n, m;
        cin >> n >> m;
        if (n == 0) break;

        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        cout << "Case " << tc << ":\n";
        dp.assign(n + 1, vector<ll>(n + 1, -1));
        for (int i = 0; i < m; ++i) {
            int r;
            cin >> r;
            cout << solve(0, r) << '\n';
        }
    }

    return 0;
}
