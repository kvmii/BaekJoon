#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c, m;
vector<pair <int, int>> vec[2001];
int capacity[2001];
int mount;
int result = 0;

int main() {
	cin >> n >> c;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c }); 
	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	for (int i = 1; i <= n; i++) {
		result += capacity[i];
		mount -= capacity[i];
		for (int j = 0; j < vec[i].size(); j++) {
			int a = vec[i][j].first;
			int b = vec[i][j].second;

			if (mount + b <= c) {
				mount += b;
				capacity[a] += b;
			}

			else {
				int cnt = b - (c - mount);
				for (int t = n; t >= a + 1; t--) {
					if (capacity[t] >= cnt) {
						capacity[t] -= cnt;
						cnt = 0;
						break;
					}
					else {
						cnt -= capacity[t];
						capacity[t] = 0;
					}
				}

				mount = c;
				capacity[a] += b - cnt;
			}
		}

	}

	cout << result;
}