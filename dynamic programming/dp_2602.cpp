#include <iostream>
#include <string>

using namespace std;
string str;
string bridge[2];
int dp[2][21][101];

int solve(int input, int index, int idx) {
	// ������ index, �ٸ��� index, 0�̸� õ��, 1�̸� �Ǹ�
	if (input == str.size()) return 1;
	if (dp[idx][input][index]) return dp[idx][input][index];
	for (int i = index; i < bridge[0].size(); i++) {
		if (bridge[idx][i] == str[input]) {
			// ã����
			dp[idx][input][index] += solve(input + 1, i + 1, !idx);
			// �ٸ� �ٸ����� ������ ã�Ƽ� ���
		}
	}

	return dp[idx][input][index];
}

int main() {
	cin >> str;
	cin >> bridge[0] >> bridge[1];
	cout << solve(0, 0, 0) + solve(0, 0, 1);
}