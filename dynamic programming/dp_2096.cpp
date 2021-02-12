#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];
int Min[3];
int Max[3];
int dp[2][3];
int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}

		dp[0][0] = max(Max[0], Max[1]) + arr[0];
		dp[0][1] = max(Max[0], max(Max[1], Max[2])) + arr[1];
		dp[0][2] = max(Max[1], Max[2]) + arr[2];

		dp[1][0] = min(Min[0], Min[1]) + arr[0];
		dp[1][1] = min(Min[0], min(Min[1], Min[2])) + arr[1];
		dp[1][2] = min(Min[1], Min[2]) + arr[2];

		for (int i = 0; i < 3; i++) {
			Max[i] = dp[0][i];
			Min[i] = dp[1][i];
		}
	}

	// for문을 사용할 경우 메모리 초과가 발생
	// 이유는 배열을 너무 많아지기 때문에
	// 이전 배열과 현재 배열만 저장

	cout << max(Max[0], max(Max[1], Max[2])) << " " << min(Min[0], min(Min[1], Min[2])) << endl;
	system("PAUSE");
}