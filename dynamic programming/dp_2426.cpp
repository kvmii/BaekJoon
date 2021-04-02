#include <iostream>
#include <vector>

using namespace std;
int n;
vector<pair<int, int>> coin;
int dp[10001];

int main() {
	dp[0] = 1;
	int n, k;
	cin >> n >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		coin.push_back({ a, b });
	}

	for (int i = 0; i < coin.size(); i++) {
		// ���� ���� �ϳ���
		int price = coin[i].first;
		int num = coin[i].second;
		for (int j = n; j >= 0; j--) {
			// �ߺ� ������ ���� ū ������
			for (int k = 1; k <= num && j - price * k >= 0; k++) {
				dp[j] += dp[j - price * k];
			}
		}
	}

	cout << dp[n];
}