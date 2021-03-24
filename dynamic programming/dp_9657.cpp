#include <iostream>

using namespace std;
int dp[1001];
int n;

int main() {
	cin >> n;
	dp[1] = 1;
	//1 ��� �¸�
	dp[2] = 0;
	// 0 â���¸�
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= 1000; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) {
			// 1��, 3��, 4�� �������� â���̰� �̱�� ����� �¸�
			dp[i] = 1;
		}
		else dp[i] = 0;
	}

	if (dp[n] == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}