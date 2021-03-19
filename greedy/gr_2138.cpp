#include <iostream>
#include <string>
#include <queue>

using namespace std;
int n;
string in, out;
string s;
// �Է½���ġ ����
int result = -1;

void change(int idx) {
	// ����ġ �Լ�
	if (s[idx] == '0')	s[idx] = '1';
	else s[idx] = '0';

	if (idx > 0) {
		if (s[idx - 1] == '0')	s[idx - 1] = '1';
		else s[idx - 1] = '0';
	}

	if (idx < n - 1) {
		if (s[idx + 1] == '0')	s[idx + 1] = '1';
		else s[idx + 1] = '0';
	}
}

bool same() {
	// ������ �Ǻ�
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (s[i] != out[i]) {
			check = true;
		}
	}
	return check;
}

int main() {
	cin >> n;
	cin >> in;
	cin >> out;

	int cnt = 1;
	s = in;
	change(0);
	// 0�� �ٲٰ� ����

	for (int i = 1; i < n; i++) {
		if (s[i - 1] != out[i - 1]) {
			change(i);
			cnt++;
			// �տ� ����ġ�� �ٸ��� �ڿ� ����ġ ����
		}
	}

	if (same() == false) {
		result = cnt;
		// ��������
	}

	cnt = 0;
	s = in;
	// 0�� �ȴ����� ����

	for (int i = 1; i < n; i++) {
		if (s[i - 1] != out[i - 1]) {
			change(i);
			cnt++;
		}
	}

	if (same() == false) {
		if (result == -1) result = cnt;
		// ������ �����ߴٸ�
		else result = min(result, cnt);
		// �������� �����ߴٸ� �� ���� ��
	}

	cout << result;
}