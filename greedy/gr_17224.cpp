#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k, n, l;
vector<pair<int, int>> vec;
int result = 0;

int main() {
	cin >> k >> n >> l;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ b,a });
	}

	sort(vec.begin(), vec.end());
	// 140�� �������� ����

	int i = 0;
	while (1) {
		if (l == 0) break;
		// �� Ǯ���ٸ�
		int num = vec[i].first;
		if (num > n) break;
		// Ŀ���� �� ���ĺ��ʹ� �� ũ�� ������ Ǯ������
		else {
			// �¾����� 140��
			result += 140;
			i++;
			l--;
		}
	}

	while (1) {
		// 100�� ¥��
		if (l == 0 || i == k) break;
		int num = vec[i].second;
		if (num <= n) {
			result += 100;
			i++;
			l--;
		}
		else {
			i++;
		}
	}
	cout << result;
}