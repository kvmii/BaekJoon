#include <iostream>
#include <string>
#include <queue>

using namespace std;
int n;
string in, out;
string s;
// 입력스위치 복사
int result = -1;

void change(int idx) {
	// 스위치 함수
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
	// 같은지 판별
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
	// 0을 바꾸고 시작

	for (int i = 1; i < n; i++) {
		if (s[i - 1] != out[i - 1]) {
			change(i);
			cnt++;
			// 앞에 스위치가 다르면 뒤에 스위치 변경
		}
	}

	if (same() == false) {
		result = cnt;
		// 같아지면
	}

	cnt = 0;
	s = in;
	// 0을 안누르고 시작

	for (int i = 1; i < n; i++) {
		if (s[i - 1] != out[i - 1]) {
			change(i);
			cnt++;
		}
	}

	if (same() == false) {
		if (result == -1) result = cnt;
		// 저번에 실패했다면
		else result = min(result, cnt);
		// 저번에도 성공했다면 더 작은 값
	}

	cout << result;
}