#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
int num;
priority_queue<int, vector<int>, greater<int>> pq;
int result = 0;

int main() {
	cin >> n >> k;
	cin >> num;
	for(int i = 0; i < n - 1; i++) {
		int a;
		cin >> a;
		pq.push(a - num);
		num = a;
		// �Է¹ް� �ջ������ Ű ���̸� �ֱ�
	}

	for (int i = 0; i < n - k; i++) {
		// Ű ���̰� ���� �������
		result += pq.top();
		pq.pop();
	}

	cout << result;
}
