#include <iostream>

using namespace std;
int T, n, m, sum;
int arr[10001];
int dp[10001];
int num[10001];
int result = 0;

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
		cin >> m;
		sum = 0;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			// 선행 작업 중 제일 긴 시간을 고르기
			sum = max(sum, arr[a]);
		}
		arr[i] += sum;
		// 선행 작업 + 작업이 걸리는 시간
		result = max(result, arr[i]);
	}


	// k의 선행작업이 1 ~ k - 1까지밖에 없으므로 위상정렬을 사용하지 않아도 된다
	cout << result;
}