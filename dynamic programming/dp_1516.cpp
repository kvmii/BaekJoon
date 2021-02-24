#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> vec[501];
int dp[500];
int arr[500];
int num[500];
// 선행 건물의 개수
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int dx = q.front();
		q.pop();

		for (int i = 0; i < vec[dx].size(); i++) {
			int a = vec[dx][i];
			// dx를 선행으로 하는 건물들
			num[a]--;
			dp[a] = max(dp[a], dp[dx] + arr[dx]);
			// 선행 건물 + 선행 건물의 비용
			if (num[a] == 0) {
				q.push(a);
				// 선행 건물이 없어지면
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;

			vec[a].push_back(i);
			// a가 선행되는 건물: i
			num[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (num[i] == 0) {
			// 선행 건물이 없으면
			q.push(i);
		}
	}

	bfs();

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] + arr[i] << endl;
	}
}