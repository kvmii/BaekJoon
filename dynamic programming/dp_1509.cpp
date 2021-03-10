#include <iostream>
#include <string>

using namespace std;
string str;
int dp[2501];
int arr[2501][2501];

int main() {
	cin >> str;
	str.insert(0, " ");
	for (int i = 1; i <= str.size(); i++) {
		arr[i][i] = 1;
		// 자기 자신은 팰린드롬
	}
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i + 1]) {
			arr[i][i + 1] = 1;
			// 같으면 팰린드롬
		}
	}
	for (int i = 2; i < str.size(); i++) {
		for (int j = 1; j <= str.size() - i; j++) {
			if (str[j] == str[i + j] && arr[j + 1][i + j - 1] == 1) {
				arr[j][j + i] = 1;
				// 3개부터 맨 앞과 맨 뒤가 같고 중간 문자가 팰린드롬이면 팰린드롬
			}
		}
	}

	for (int i = 1; i < str.size(); i++)
	{
		dp[i] = 987654321;
		for (int j = 1; j <= i; j++) {
			if (arr[j][i] == 1) {
				// 팰린드롬일 때
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	cout << dp[str.size() - 1];
}