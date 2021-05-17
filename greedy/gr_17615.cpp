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

	// 총 4가지의 경우의 수
	// 왼쪽, 오른쪽에서 시작
	// R이 처음나왔을 때 부터 B의 개수, B가 처음나왔을 때 부터 R의 개수
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