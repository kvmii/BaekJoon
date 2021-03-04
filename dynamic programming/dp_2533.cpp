#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
vector<int> vec[1000001];
int dp[2][1000001];
int n;
int result = 0;

int dfs(int x, int root, int node) {
	if (dp[x][root] != -1) return dp[x][root];
	if (x == 1) dp[x][root] = 1;
	else dp[x][root] = 0;

	for (int i = 0; i < vec[root].size(); i++) {
		if (vec[root][i] == node) continue;

		if (x == 1) {
			// 얼리어답터일 경우 자식은 둘다 상관 X
			dp[x][root] += min(dfs(1, vec[root][i], root), dfs(0, vec[root][i], root));
		}
		else {
			// 얼리어답터가 아닐 경우 자식은 무조건 얼리어답터
			dp[x][root] += dfs(1, vec[root][i], root);
		}
	}

	return dp[x][root];
}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	cout << min(dfs(1, 1, 0), dfs(0, 1, 0));
	return 0;
}