#include <iostream>

using namespace std;

int dp[1001];
int n;

int main() {
	cin >> n;
	if (n % 7 == 1 || n % 7 == 3) cout << "CY";
	// 상근이 패승패승승승승이 반복
	// 7을 주기로 반복하므로 7로 나누어 보기
	else cout << "SK";
}