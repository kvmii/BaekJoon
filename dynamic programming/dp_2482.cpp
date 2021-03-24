#include <iostream>
#define MAX 1000000003;

using namespace std;
long long dp[1001][1001];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= 1000; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MAX;
			// 일자로 세운다고 했을 때 첫번째 것을 고르면 두번째 것을 못 고르기 때문에 i - 2개중에 j - 1개를 선택
			// 고르지 않으면 i - 1개 중에 j개를 선택
		}
	}

	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MAX;
	// 원형이므로 맨 뒤에 있는 것도 선택불가
	// 처음을 고르면 n - 3중에 k-1개 선택
	// 고르지 않으면 n - 1개중에 k개 선택
}