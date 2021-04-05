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
		// P의 개수 확인
		else if (p >= 2 && str[i + 1] == 'P') {
			// P가 두개 이상이고 다음이 P면 PPAP
			p -= 2;
			// PPAP를 P로 바꿔서 2개 줄이기
		}
		else {
			cout << "NP";
			return 0;
		}
	}

	if (p == 1) cout << "PPAP";
	// PPAP라면 p가 1이어야 한다
	else cout << "NP";
}