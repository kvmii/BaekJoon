#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string in, out;
bool check = false;

void change(string str) {
	// 뒤에서부터 접근
	if (str.length() < in.length()) return;
	// 길이가 더 짧아지면 불가능

	if (str == in) {
		// 만약 가능하다면
		check = true;
		return;
	}

	if (str.back() == 'B') {
		// 뒤가 B면 B를 없애고 뒤집기
		str.pop_back();
		reverse(str.begin(), str.end());
		change(str);
	}
	else {
		// 뒤가 A면 그냥 A를 없애기
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