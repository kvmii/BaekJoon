#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	vector<int>vec;
	int dp[1000];
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vec.push_back(n);
	}

	sort(vec.begin(), vec.end());
	
	dp[0] = vec[0];


	int result = dp[0];

	for (int i = 1; i < vec.size(); i++) {
		dp[i] = dp[i - 1] + vec[i];
		result = result + dp[i];
	}

	cout << result;
}