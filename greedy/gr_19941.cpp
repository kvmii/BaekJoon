#include <iostream>

using namespace std;
int n, k;
string str;
int visited[20001];
int result = 0;

int main() {
	cin >> n >> k;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			// ����̸�
			for (int j = i - k; j <= i + k; j++) {
				// �翷���� �Ÿ����� ã��
				if (j >= 0 && j < n && visited[j] != 1) {
					// �������� �ְ� �湮���� �ʾҴٸ�
					if (str[j] == 'H') {
						result++;
						visited[j] = 1;
						break;
					}
				}
			}
		}
	}

	cout << result;
}