#include <iostream>
#include <string>

using namespace std;
string str;
string bridge[2];
int dp[2][21][101];

int solve(int input, int index, int idx) {
	// 문자의 index, 다리의 index, 0이면 천사, 1이면 악마
	if (input == str.size()) return 1;
	if (dp[idx][input][index]) return dp[idx][input][index];
	for (int i = index; i < bridge[0].size(); i++) {
		if (bridge[idx][i] == str[input]) {
			// 찾으면
			dp[idx][input][index] += solve(input + 1, i + 1, !idx);
			// 다른 다리에서 다음거 찾아서 재귀
		}
	}

	return dp[idx][input][index];
}

int main() {
	cin >> str;
	cin >> bridge[0] >> bridge[1];
	cout << solve(0, 0, 0) + solve(0, 0, 1);
}