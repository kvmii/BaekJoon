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
	// n-1���� ������ ����� ���� ���ϱ�
	// n-1������ ���ڰ� 0, 1, 2�� �������� ������ 3�� ����� ���� �� �ִ�.
} 