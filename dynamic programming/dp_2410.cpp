#include <iostream>
#include <vector>
#define mod 1000000000

using namespace std;
int n;
long long dp[1000001];
vector<long long> vec;


int main() {
	cin >> n;
	dp[0] = 1;

	for (int i = 1; i <= 1000000; i *= 2) {
		vec.push_back(i);
	}

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= vec[i])
				dp[j] = (dp[j] + dp[j - vec[i]]) % mod;
			// 코인문제와 비슷한 풀이
		}
	}

	cout << dp[n];
}