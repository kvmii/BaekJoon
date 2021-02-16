#include <iostream>

using namespace std;

int visited[1001];
int arr[1001][1001];
int n, m;
int result = 0;

void dfs(int x) {
	visited[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[i][x] == 1 && visited[i] != 1) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] != 1) {
			dfs(i);
			result++;
		}
	}

	cout << result << endl;
	system("PAUSE");
}