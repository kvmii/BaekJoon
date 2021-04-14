#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int T, n, score;
int dp[10001];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> coin;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			coin.push_back(num);
		}
		cin >> score;
		dp[0] = 1;
		for (int i = 0; i < coin.size(); i++) {
			for (int j = 1; j <= score; j++) {
				if (j >= coin[i]) {
					dp[j] += dp[j - coin[i]];
					// 코인문제
				}
			}
		}
		cout << dp[score] << '\n';
	}
}