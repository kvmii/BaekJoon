#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int n, T;
vector<int> arr[1001];
bool visited[1001] ;


void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		int cnt = arr[x][i];
		if (!visited[cnt]) {
			dfs(cnt);
		}
	}
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {

		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));

		cin >> n;

		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			arr[j].push_back(a);
		}

		int score = 0;

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				score++;
			}
		}

		cout << score << endl; 
	}
	return 0;
}