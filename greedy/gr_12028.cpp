#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, p, l;
int result = 0;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> Q;
	// ���ϸ����� ���� ������ ����
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		if (p < l) {
			// �ڸ��� ���������
			for (int j = 0; j < p; j++) {
				int a;
				cin >> a;
			}
			Q.push(1);
			// �ּҴ����� 1�� �ֱ�
		}
		else {
			vector<int> vec;
			for (int j = 0; j < p; j++) {
				int a;
				cin >> a;
				vec.push_back(a);
			}
			sort(vec.begin(), vec.end(), greater<int>());
			// ū ������� ����
			Q.push(vec[l - 1]);
			// l��°�� ū �Ͱ� ���� ���ϸ����� ���� �����̰� �ö�
		}
	}

	while (!Q.empty()) {
		if (m - Q.top() >= 0) {
			// ���� �ͺ��� �ϳ��� ��û
			m -= Q.top();
			Q.pop();
			result++;
		}
		else break;
	}

	cout << result;
}