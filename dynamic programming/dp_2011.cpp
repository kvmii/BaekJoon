#include <iostream>
#include <string>

using namespace std;

string str;
int arr[5001];
int dp[5001];

int main() {
	cin >> str;
	for (int i = 1; i <= str.length(); i++) {
		arr[i] = str[i - 1] - '0';
	}

	for (int i = 1; i <= str.length(); i++) {
		if (arr[i] <= 9 && arr[i] > 0) {
			if (i == 1) dp[1] = 1;
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		}
		if (arr[i - 1] * 10 + arr[i] <= 26 && arr[i - 1] * 10 + arr[i] >= 10) {
			if (i == 2) dp[2] = dp[2] + 1;
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}

	cout << dp[str.length()] % 1000000 << endl;

	return 0;
}