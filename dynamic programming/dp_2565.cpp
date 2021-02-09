#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;
int n, m, T;
int dp[101];
int num = 1;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		arr.push_back({ n, m });
	}

	sort(arr.begin(), arr.end());
	// 오름차순으로 정렬하기

	for (int i = 0; i < T; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j].second < arr[i].second && dp[i] < dp[j] + 1) {
				// 증가하는 가장 긴 수열 구하기
				dp[i] = dp[j] + 1;
			}
		}
		num = max(num, dp[i]);
	}

	cout << T - num << endl;
	//전체 - 가장 긴 수열 = 전깃줄 개수
	system("PAUSE");
}