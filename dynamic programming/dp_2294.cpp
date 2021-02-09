#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int  dp[101];
int result[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int max = 987654321;

	cin >> n >> k;

	for (int i = 0; i <= k; i++) {
		result[i] = max;
	}

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}
	result[0] = 1;

	for (int i = 0; i < n; i++) {
		result[dp[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		int T = dp[i];
		for (int j = T; j <= k; j++) {
			if (j < T)
				continue;
			result[j] = min(result[j],result[j - T] + 1);
		}
	}

	if (result[k] == max) {
		cout << -1;
	}
	else
		cout << result[k] << endl;

	return 0;
}