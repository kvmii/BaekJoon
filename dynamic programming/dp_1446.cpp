#include<iostream>
#include <vector>

using namespace std;

int main() {
	int t, N;
	int start, end, length;
	int dp[10001] = { 0, };
	vector<pair<int,int>> graph[10001];
	cin >> t >> N;

	for (int j = 1; j <= N; j++) {
		dp[j] = j;
	}

	for (int i = 0; i < t; i++) {
		cin >> start >> end >> length;
		if (end > N) continue;
		graph[end].push_back({ start, length });
	}



	for (int i = 1; i <= N; i++) {
		if (graph[i].size() != 0) {
			for (auto d:graph[i]) {
				dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[d.first] + d.second));
			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cout << dp[N];
}