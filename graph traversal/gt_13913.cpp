#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int visited[100001];
vector<long long> result;
int n, m;

bool visit(int n) {
	if (n < 0 || n > 100000 || visited[n]) return false;
	return true;
}

void bfs(int x, int y) {
	queue<pair<int, vector<long long>>> q;
	vector<long long> vec;
	vec.push_back(x);
	q.push({ x, vec });
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front().first;
		vector<long long> hide = q.front().second;
		q.pop();
		if (dx == y) {
			result = hide;
			break;
		}
		vector<long long> arr1 = hide;
		vector<long long> arr2 = hide;
		vector<long long> arr3 = hide;
		// 벡터에 저장

		if (visit(2 * dx)) {
			arr1.push_back(2 * dx);
			visited[2 * dx] = 1;
			q.push({ 2 * dx, arr1 });
		}

		if (visit(dx + 1)) {
			arr2.push_back(dx + 1);
			visited[dx + 1] = 1;
			q.push({ dx + 1, arr2 });
		}

		if (visit(dx - 1)) {
			arr3.push_back(dx - 1);
			visited[dx - 1] = 1;
			q.push({ dx - 1, arr3 });
		}
	}
}

int main() {
	// 1697과 비슷한 문제
	cin >> n >> m;
	if (n >= m) {
		// n이 m보다 클 경우 시간 초과가 발생
		// n이 m보다 클 경우에는 -1을 하는 경우밖에 없으므로 따로 처리
		cout << n - m << endl;
		for (int i = n; i >= m; i--) {
			cout << i << " ";
		}
	}

	else {
		bfs(n, m);
		cout << result.size() - 1 << endl;
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
	}
}