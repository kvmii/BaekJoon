#include <iostream>
#include <string>

using namespace std;
string n, m;
int result = 0;

int main() {
	cin >> n >> m;
	int a = stoi(n);
	int b = stoi(m);
	if (a == b) {
		// a와 b가 똑같은 문자라면
		for (int i = 0; i < n.size(); i++) {
			if (n[i] == '8') result++;
			// 8 개수 세기
		}
	}
	else {
		if (n.size() == m.size()) {
			// 사이즈가 다를경우 무조건 0이다
			for (int i = 0; i < n.size(); i++) {
				if (n[i] == m[i]) {
					// i번째 문자열이 같으면
					if (n[i] == '8' && m[i] == '8') {
						// 같은데 8이면
						result++;
					}
				}
				else {
					break;
				}
			}
		}
	}

	cout << result;
}