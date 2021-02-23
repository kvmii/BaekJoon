#include <iostream>
#include <queue>

int result[101];
int arr[101][101];
int visited[101];
using namespace std;
int n, m;
int num1, num2;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = 1;

	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[i][dx] == 1 && visited[i] != 1) {
				visited[i] = 1;
				result[i] = result[dx] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> num1 >> num2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	bfs(num1);
	if (result[num2] != 0)
		cout << result[num2];
	else
		cout << "-1";
}