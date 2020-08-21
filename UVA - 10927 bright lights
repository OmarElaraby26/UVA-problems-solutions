// Author: Omar_Elaraby

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define px first.first
#define py first.second
#define ph second
#define Point pair<int, int>
#define Pole pair<Point, int>

vector<Point> ans;

Point slope(Pole a) {
	if (a.px == 0) return Point(1, 0);
	if (a.py == 0) return Point(0, a.px / abs(a.px));

	int g = __gcd(abs(a.px), a.py);
	a.px /= g;
	a.py /= g;
	return Point(a.py, a.px);
}

void check(const vector<Pole> &v) {
	Pole temp(make_pair(make_pair(0, 0), -1));
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].ph <= temp.ph) ans.emplace_back(Point(v[i].px, v[i].py));
		else temp = v[i];
	}
}

bool cmp(const Pole&a, const Pole &b) {
	if (a.px == 0) return a.py < b.py;
	return abs(a.px) < abs(b.px);
}

int main() {

	int n, tc = 0;
	while (scanf("%d", &n), n) {
		map<Point, vector<Pole> > mp;
		while (n--) {
			Pole a;
			scanf("%d %d %d", &a.px, &a.py, &a.ph);
			mp[slope(a)].emplace_back(a);
		}

		for (auto &it : mp) {
			sort(it.second.begin(), it.second.end(), cmp);
			check(it.second);
		}

		printf("Data set %d:\n", ++tc);
		if (ans.size() == 0) printf("All the lights are visible.\n");
		else {
			sort(ans.begin(), ans.end());
			printf("Some lights are not visible:\n");
			for (int i = 0; i < ans.size(); ++i) {
				printf("x = %d, y = %d", ans[i].x, ans[i].y);
				if (i + 1 == ans.size()) printf(".\n");
				else printf(";\n");
			}
		}

		ans.clear();
	}

	return 0;
}
