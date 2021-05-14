// Author: Omar_Elaraby
#include <bits/stdc++.h>
using namespace std;

int dp[10000][21][21];
vector<int> a;
int K;
// j is on the fly
// because it can be calculated as follow:
// j = N - 1 - (i + InsertedBefore) - InsertedBefore, where N = a.size() + cntAllInserted
int solve(const int i, const int InsertedBefore, const int cntAllInserted,
		const int j) {
	if (cntAllInserted > K) return 1e9; // return infinity
	if (i >= j) return 0;

	int &ans = dp[i][InsertedBefore][cntAllInserted];
	if (ans != -1) return ans;

	if (a[i] == a[j]) {
		return ans = solve(i + 1, InsertedBefore, cntAllInserted, j - 1);
	}

	int p1 = 1 + solve(i + 1, InsertedBefore, cntAllInserted + 1, j);
	int p2 = 1 + solve(i, InsertedBefore + 1, cntAllInserted + 1, j - 1);
	return ans = min(p1, p2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int tt, tc = 0;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n >> K;
		a.resize(n);
		for (int &i : a) {
			cin >> i;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= K; ++j) {
				for (int l = 0; l <= K; ++l) {
					dp[i][j][l] = -1;
				}
			}
		}

		int res = solve(0, 0, 0, n - 1);

		cout << "Case " << ++tc << ": ";
		if (res == 0) cout << "Too easy\n";
		else if (res > K) cout << "Too difficult\n";
		else cout << res << '\n';
	}

	return 0;
}
