#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define EPS 1e-9

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int tt, tc = 0;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		const int n = s.size();
		vector<int> dp(n);

		for (int i = n - 1; i >= 0; --i) {
			vector<int> new_dp(n);
			for (int j = i + 1; j < n; ++j) {
				if (s[i] == s[j]) new_dp[j] = dp[j - 1];
				else {
					int p1 = 1 + dp[j - 1];
					int p2 = 1 + dp[j];
					int p3 = 1 + new_dp[j - 1];
					new_dp[j] = min( { p1, p2, p3 });
				}
			}
			dp = new_dp;
		}

		cout << "Case " << ++tc << ": " << dp.back() << '\n';
	}

	return 0;
}
