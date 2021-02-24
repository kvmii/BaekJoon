#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[1001];
int dp[1001];
int maximum = 1;
vector<int> vec;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				maximum = max(dp[i], maximum);
				// 최댓값 저장
			}
		}
	} 


	int num = 987654321;

	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == maximum && arr[i] < num) {
			num = arr[i];
			vec.push_back(arr[i]);
			maximum--;
		}
	}
	cout << vec.size() << endl;

	reverse(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	// 증가하는 수열은 많이 봐서 쉬웠지만 그 수열을 구하는 것이 문제였다
	// 처음에는 1,2,3... 순서로 해서 dp가 같으면 vec에 push_back하였으나
	// 1 5 6 2 3과 같은 반례가 나왔다
	// 그래서 최댓값을 저장한 후 거꾸로 접근한 후 reverse를 해주었다
}