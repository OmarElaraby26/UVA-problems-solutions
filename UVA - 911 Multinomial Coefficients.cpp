#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll C(vector<vector<int>> &mat) {
    for (int r = 1; r < mat.size(); ++r) {
        for (int i = 0; i < mat[0].size(); ++i) {
            for (int j = 0; j < mat[r].size(); ++j) {
                int g = __gcd(mat[0][i], mat[r][j]);
                mat[0][i] /= g;
                mat[r][j] /= g;
            }
        }
    }

    ll ans = 1;
    for (int i = 0; i < mat[0].size(); ++i) {
        ans *= mat[0][i];
    }
    for (int i = 1; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            ans /= mat[i][j];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    while (cin >> n) {
        int k;
        cin >> k;
        vector<int> z(k);
        for (int i = 0; i < k; ++i) {
            cin >> z[i];
        }

        
         // build matrix that we will calculate [n! / (z[0]! * z[1]! * ... * z[k-1]!)] through it.
        vector<vector<int>> mat(k + 1);
        mat[0].resize(n);
        iota(mat[0].begin(), mat[0].end(), 1);
        for (int i = 1; i < mat.size(); ++i) {
            mat[i].resize(z[i - 1]);
            iota(mat[i].begin(), mat[i].end(), 1);
        }

        // calculating [n! / (z[0]! * z[1]! * ... * z[k-1]!)]
        cout << C(mat) << '\n';
    }

    return 0;
}
