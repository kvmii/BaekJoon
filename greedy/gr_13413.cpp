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
			// 검은색 개수 세기
		}
		int num = bin - bout;
		
		if (num > 0) {
				for (int i = 0; i < m; i++) {
					if (in[i] != out[i] && in[i] == 'B') {
						// 흰색 개수 맞추기
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
						// 검은색 개수 맞추기
						in[i] = 'B';
						result++;
						num++;
						if (num == 0) break;
					}
				}
		}

		// 흰색과 검은색 개수가 같을 경우 바꾸기만 하면 된다
		int score = count(in, out);
		if (score % 2 == 0) result += score / 2;
		// 짝수면 /2
		else result += score / 2 + 1;
		// 홀수면 한번 더 바꾸기
		cout << result << endl;
	}
}