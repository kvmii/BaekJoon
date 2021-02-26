#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec[100002];
int visited[100002] = { 0, };
int result[100002];
int n, a, b;

void dfs(int x) {
	visited[x] = 1;

	for (int i = 0; i < vec[x].size(); i++) {
		int cnt = vec[x][i];
		if (visited[cnt] != 1) {
			result[cnt] = x;
			dfs(cnt);
		}
	}
}
 

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << result[i] << endl;
	}

	return 0;
}