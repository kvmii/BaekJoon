#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string in, out;
bool check = false;

void change(string str) {
	// �ڿ������� ����
	if (str.length() < in.length()) return;
	// ���̰� �� ª������ �Ұ���

	if (str == in) {
		// ���� �����ϴٸ�
		check = true;
		return;
	}

	if (str.back() == 'B') {
		// �ڰ� B�� B�� ���ְ� ������
		str.pop_back();
		reverse(str.begin(), str.end());
		change(str);
	}
	else {
		// �ڰ� A�� �׳� A�� ���ֱ�
		str.pop_back();
		change(str);
	}
}

int main() {
	cin >> in;
	cin >> out;

	change(out);

	if (check) cout << 1;
	else cout << 0;
}