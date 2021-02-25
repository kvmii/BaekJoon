#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> vec;
int dp[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());
	if(vec.size() > 1)
	dp[1] = vec[0] + vec[1];

	for (int i = 2; i < vec.size(); i++) {
		dp[i] = 2 * dp[i - 1] + vec[i];
	}


	cout << dp[n - 1];
}