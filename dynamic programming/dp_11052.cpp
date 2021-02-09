#include <iostream>
#include <algorithm>
using namespace std;

int pi[1001];
int dp[1001];

int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> dp[i];
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			pi[i] = max(pi[i], pi[i - j] + dp[j]);

	cout << pi[N];
}