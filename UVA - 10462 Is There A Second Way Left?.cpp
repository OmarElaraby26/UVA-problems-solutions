// Author: Omar_Elaraby

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
	vector<int> par, size;
	UnionFind(const int sz) {
		par.resize(sz);
		size.resize(sz, 1);
		iota(par.begin(), par.end(), 0);
	}

	void reset(const int sz) {
		par.resize(sz);
		size.resize(sz, 1);
		for (int i = 0; i < sz; ++i) {
			par[i] = i;
			size[i] = 1;
		}
	}

	int find(const int u) {
		if (u == par[u]) return u;
		return par[u] = find(par[u]);
	}

	void link(const int a, const int b) {
		int x = find(a), y = find(b);
		if (x == y) return;
		if (size[x] < size[y]) swap(x, y);
		par[y] = x;
		size[x] += size[y];
	}
  
  // number of nodes of the component which u belongs to
	int componentSize(const int node) {
		int root = find(node);
		return size[root];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  // kruskal algorithm with DSU 

	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		cout << "Case #" << tc << " : ";

		int n, e;
		cin >> n >> e;
		vector<pair<int, pair<int, int> > > edge(e);
		for (int i = 0; i < e; ++i) {
			int a, b;
			int c;
			cin >> a >> b >> c;
			--a, --b;
			edge[i] = make_pair(c, make_pair(a, b));
		}
		sort(edge.begin(), edge.end());

		UnionFind mst(n);
		vector<int> bestMstEdge; // store index of edges
		for (int i = 0; i < edge.size(); ++i) {
			int u = edge[i].second.first, v = edge[i].second.second;
			if (mst.find(u) != mst.find(v)) {
				bestMstEdge.emplace_back(i);
				mst.link(u, v);
			}
		}

		// number of connected components in spanning tree must be 1
		// so number of nodes in spanning tree must be (n)
		if (mst.componentSize(0) != n) { // or bestMstEdge.size() != n - 1
			cout << "No way\n"; // there is no spanning tree
			continue;
		}

		// spanning tree is found
		// now let's search for second best MST

		long long ans = LLONG_MAX;
		for (int i = 0; i < bestMstEdge.size(); ++i) {
			mst.reset(n);
			long long cnt = 0;
			for (int j = 0; j < edge.size(); ++j) {
				if (j == bestMstEdge[i]) continue;
				int u = edge[j].second.first, v = edge[j].second.second;
				if (mst.find(u) != mst.find(v)) {
					cnt += edge[j].first;
					mst.link(u, v);
				}
			}

			// number of connected components in spanning tree must be 1
			// so number of nodes in spanning tree must be (n)
			// if the condition is false then it is forest not tree
			if (mst.componentSize(0) == n) ans = min(ans, cnt);
		}

		if (ans == LLONG_MAX) cout << "No second way\n";
		else cout << ans << '\n';
	}

	return 0;
}
