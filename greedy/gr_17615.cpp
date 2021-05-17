#include <iostream>

using namespace std;
int n;
char arr[500001];
bool check;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// �� 4������ ����� ��
	// ����, �����ʿ��� ����
	// R�� ó�������� �� ���� B�� ����, B�� ó�������� �� ���� R�� ����
	int score = 987654321, result = 0;
	check = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'B') check = true;
		else {
			if (check == true) result++;
		}
	}
	
	score = min(score, result);

	result = 0;
	check = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'R') check = true;
		else {
			if (check == true) result++;
		}
	}

	score = min(score, result);

	result = 0;
	check = false;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 'B') check = true;
		else {
			if (check == true) result++;
		}
	}

	score = min(score, result);

	result = 0;
	check = false;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 'R') check = true;
		else {
			if (check == true) result++;
		}
	}

	score = min(score, result);

	cout << score;
}