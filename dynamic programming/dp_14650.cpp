#include <iostream>
#define MOD 1000000009

using namespace std;
int n;

long long solve(int n) {
	if (n == 0) return 1;
	return(solve(n - 1) * 3) % MOD;
}

int main() {
	cin >> n;
	if (n == 1) cout << 0;
	else cout << (2 * solve(n - 2)) % MOD;
	// n-1까지 숫자의 경우의 수를 구하기
	// n-1길이의 숫자가 0, 1, 2중 무엇으로 끝나도 3의 배수로 만들 수 있다.
} 