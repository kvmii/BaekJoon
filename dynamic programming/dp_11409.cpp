#include <iostream>

using namespace std;

int arr[501][2];
int dp[501][501];

int cal(int x, int y) {
	if (dp[x][y])
		return dp[x][y];
	if (x == y) return 0;
	if (x + 1 == y) return arr[x][0] * arr[x][1] * arr[y][1];

	dp[x][y] = 2147483647;

	for (int i = x; i < y; i++) {
		dp[x][y] = min(dp[x][y], cal(x, i) + cal(i + 1, y) + arr[x][0] * arr[i][1] * arr[y][1]);
		// x와 y의 중간 숫자인 i
		// 행렬의 곱은 x부터 i까지의 곱 + i+1부터 y까지의 곱 + arr[i]와 arr[i+1]의 곱(이걸 아는게 포인트)
		// 유사문제 11066
	}

	return dp[x][y];
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	cout << cal(0, n - 1);
}