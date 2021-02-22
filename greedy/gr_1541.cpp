#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
int x;
int result = 0;

int main() {
	cin >> str;

	string num = "";
	int sum = 0;
	bool minus = false;

	// - 가 나온 이후로 다 빼주기
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) {
				sum -= stoi(num);
			}
			else {
				sum += stoi(num);
				// 그전까지는 계속 +
			}
			if (str[i] == '-') {
				// -가 처음 등장했다면
				minus = true;
			}

			num = "";
		}
		else
			num += str[i];
		// 부호가 안나오면 string으로 더해주기
	}

	cout << sum;
	
}