#include <iostream>

using namespace std;

int dp[1001];
int n;

int main() {
	cin >> n;
	if (n % 7 == 1 || n % 7 == 3) cout << "CY";
	// ����� �н��н½½½��� �ݺ�
	// 7�� �ֱ�� �ݺ��ϹǷ� 7�� ������ ����
	else cout << "SK";
}