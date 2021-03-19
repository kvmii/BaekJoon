#include <iostream>
#include <string>

using namespace std;
string in, out;
int n, m;

int count(string str1, string str2) {
	int score = 0;
	for (int i = 0; i < m; i++) {
		if (str1[i] != str2[i]) score++;
	}
	return score;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> m;
		cin >> in >> out;

		int result = 0;

		int bin = 0, bout = 0;
		for (int i = 0; i < m; i++) {
			if (in[i] == 'B') bin++;
			if (out[i] == 'B') bout++;
			// ������ ���� ����
		}
		int num = bin - bout;
		
		if (num > 0) {
				for (int i = 0; i < m; i++) {
					if (in[i] != out[i] && in[i] == 'B') {
						// ��� ���� ���߱�
						in[i] = 'W';
						result++;
						num--;
						if (num == 0) break;
					}
				}
		}
		else if(num < 0) {
				for (int i = 0; i < m; i++) {
					if (in[i] != out[i] && in[i] == 'W') {
						// ������ ���� ���߱�
						in[i] = 'B';
						result++;
						num++;
						if (num == 0) break;
					}
				}
		}

		// ����� ������ ������ ���� ��� �ٲٱ⸸ �ϸ� �ȴ�
		int score = count(in, out);
		if (score % 2 == 0) result += score / 2;
		// ¦���� /2
		else result += score / 2 + 1;
		// Ȧ���� �ѹ� �� �ٲٱ�
		cout << result << endl;
	}
}