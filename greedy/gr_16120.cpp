#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> str;
	int p = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') p++;
		// P�� ���� Ȯ��
		else if (p >= 2 && str[i + 1] == 'P') {
			// P�� �ΰ� �̻��̰� ������ P�� PPAP
			p -= 2;
			// PPAP�� P�� �ٲ㼭 2�� ���̱�
		}
		else {
			cout << "NP";
			return 0;
		}
	}

	if (p == 1) cout << "PPAP";
	// PPAP��� p�� 1�̾�� �Ѵ�
	else cout << "NP";
}