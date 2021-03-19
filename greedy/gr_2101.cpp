#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k;
vector<int> vec;

int main() {
	cin >> n >> m >> k;
	if (n < m + k - 1 || n > m * k) {
		// ������ �Ұ����� ��
		cout << -1;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
	}

	reverse(vec.begin(), vec.begin() + k);
	// ó���� k��ŭ ������ �ָ� �����ϴ� ������ k���� ����
	// �׸��� ��ü�� m���� ���� �� ���� ������ �ָ� �ȴ�.

	int cnt = k;


	for (int i = 1; i < m; i++) {
		int idx = cnt;

		cnt += (n - cnt) / (m - i);
		// ���� �� / �����ϴ� �������� ���� ��

		reverse(vec.begin() + idx, vec.begin() + cnt);
		// ������
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}