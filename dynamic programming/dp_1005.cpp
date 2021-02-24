#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int T, n, m, k;
int arr[1001];
int dp[1001];
int num[1001];
vector<int> vec[1001];
queue<int> q;

void bfs() {
	// dp_1516과 유사한 문제
	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		for (int i = 0; i < vec[dx].size(); i++) {
			num[vec[dx][i]]--;
			dp[vec[dx][i]] = max(dp[vec[dx][i]], dp[dx] + arr[dx]);
			if (num[vec[dx][i]] == 0) {
				q.push(vec[dx][i]);
			}
		}
	}
}

void clear() {
	// 초기화
	for (int i = 1; i < 1001; i++) {
		dp[i] = 0;
		vec[i].clear();
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			// a = 선행건물
			num[b]++;
			// b를 짓기 위한 선행건물의 개수
		}
		cin >> k;

		for (int i = 1; i <= n; i++) {
			if (num[i] == 0) {
				q.push(i);
			}
		}

		bfs();
		cout << dp[k] + arr[k] << endl;
		// 선행건물들이 지어지는 시간 + k가 지어지는 시간
		clear();
	}
}