// Omar_Elaraby
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int tt, tc = 0;
	cin >> tt;
	while (tt--) {
		int N, K;
		cin >> N >> K;
		vector<int> a(N);
		for (int &i : a) {
			cin >> i;
		}

		vector<vector<int> > dp(K + 1, vector<int>(K + 1));
		for (int i = N - 1; i >= 0; --i) {
			for (int before = K; before >= 0; --before) {
				for (int cnt = before; cnt <= K; ++cnt) {
					const int j = (N + cnt - 1) - (i + before) - before;
					if (i >= j) continue;
					int &ans = dp[before][cnt];
//					if (a[i] == a[j]) ans = dp[before][cnt];
					if (a[i] != a[j]) {
						int p1 = 1e9, p2 = 1e9; // infinity initial value
						if (cnt + 1 <= K) p1 = 1 + dp[before][cnt + 1];
						if (cnt + 1 <= K && before + 1 <= K) {
							p2 = 1 + dp[before + 1][cnt + 1];
						}
						ans = min(p1, p2);
					}
				}
			}
		}

		cout << "Case " << ++tc << ": ";
		const int x = dp[0][0];
		if (x == 0) cout << "Too easy\n";
		else if (x > K) cout << "Too difficult\n";
		else cout << x << '\n';
	}

	return 0;
}
