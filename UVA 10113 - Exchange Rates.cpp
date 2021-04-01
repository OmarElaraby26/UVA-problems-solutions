#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(const ll a, const ll b) {
	return a / __gcd(a, b) * b;
}

class UnionFind {
private:
	string search(const string &u) {
		if (par[u] == u) return u;
		return par[u] = search(par[u]);
	}
	void increaseAllGroupBy(const string &a, const ll factor) {
		for (auto &it : val) {
			if (find(it.first) == find(a)) {
				it.second *= factor;
			}
		}
	}


	ll getGCDofGroup(const string &root) {
		ll g = 0;
		for (const auto &it : par) {
			if (find(it.second) == find(root)) {
				g = __gcd(g, val[it.first]);
			}
		}
		return g;
	}

	void decreaseAllGroupBy(const string &root, const ll factor) {
		for (const auto &it : par) {
			if (find(it.second) == find(root)) {
				val[it.first] /= factor;
			}
		}
	}

public:
	map<string, string> par;
	map<string, int> siz;
	map<string, ll> val;
	string find(const string &u) {
		if (!par.count(u)) {
			par[u] = u;
			siz[u] = 1;
			val[u] = 1;
		}
		return search(u);
	}

	void link(ll a, string x, ll b, string y) { // y -> x
		string rx = find(x);
		string ry = find(y);
		if (siz[rx] < siz[ry]) {
			swap(x, y);
			swap(a, b);
			swap(rx, ry);
		}

		ll l = lcm(a, val[x]);
		ll factor = l / a;
		a *= factor;
		b *= factor;

		factor = l / val[x];
		increaseAllGroupBy(rx, factor);

		l = lcm(b, val[y]);
		factor = l / b;
		a *= factor;
		increaseAllGroupBy(rx, factor);
		b *= factor;

		factor = l / val[y];
		increaseAllGroupBy(ry, factor);

		siz[rx] += siz[ry];
		par[ry] = rx;

		decreaseAllGroupBy(rx, getGCDofGroup(rx));
	}

	bool isConn(const string &a, const string &b) {
		return find(a) == find(b);
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	UnionFind dsu;

	char t;
	while (cin >> t) {
		if (t == '.') break;
		if (t == '!') {
			ll m, n;
			string x, y;
			char e; // equal sign
			cin >> m >> x >> e >> n >> y;
			dsu.link(m, x, n, y);
		}
		else { // t == '?'
			string x, y;
			char e; // equal sign
			cin >> x >> e >> y;
			if (dsu.isConn(x, y)) {
				ll g = __gcd(dsu.val[x], dsu.val[y]);
				cout << dsu.val[x] / g << ' ' << x << " = " << dsu.val[y] / g
						<< ' ' << y << '\n';
			}
			else cout << "? " << x << " = " << "? " << y << '\n';
		}
	}

	return 0;
}

