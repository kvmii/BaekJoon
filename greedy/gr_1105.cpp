#include <iostream>
#include <string>

using namespace std;
string n, m;
int result = 0;

int main() {
	cin >> n >> m;
	int a = stoi(n);
	int b = stoi(m);
	if (a == b) {
		// a�� b�� �Ȱ��� ���ڶ��
		for (int i = 0; i < n.size(); i++) {
			if (n[i] == '8') result++;
			// 8 ���� ����
		}
	}
	else {
		if (n.size() == m.size()) {
			// ����� �ٸ���� ������ 0�̴�
			for (int i = 0; i < n.size(); i++) {
				if (n[i] == m[i]) {
					// i��° ���ڿ��� ������
					if (n[i] == '8' && m[i] == '8') {
						// ������ 8�̸�
						result++;
					}
				}
				else {
					break;
				}
			}
		}
	}

	cout << result;
}