#include <iostream>
#include <vector>

using namespace std;
long long dp[41];
int n, m;
vector<int> vec;
long long result = 1;

int main() {
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	// 자리를 바꾸는 경우의 수

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec.size() == 1 && i == 0) {
			// m이 1일 때
			if (vec[i] == 1 || vec[i] == n) { 
				// 끝자리를 막았다면
				result *= dp[n - 1];
			}
			else
			{
				result *= dp[vec[i] - 1];
				result *= dp[n - vec[i]];
			}
		}
		else if (i == 0) {
			// 첫번째 막은 곳
			if(vec[i] != 1)
			result = result * dp[vec[i] - 1];
		}
		else if (i == vec.size() - 1) {
			// 마지막으로 막은 곳
			if(vec[i] - vec[i - 1] != 1)
			result = result * dp[vec[i] - vec[i - 1] - 1];
			if(vec[i] != n)
			result = result * dp[n - vec[i]];
		}
		else{
			if(vec[i] - vec[i - 1] != 1)
			result = result * dp[vec[i] - vec[i - 1] - 1];
		}
	}

	if (m == 0) {
		// 아무자리도 막지 않았을 때
		result = dp[n];
	}
	cout << result;
}