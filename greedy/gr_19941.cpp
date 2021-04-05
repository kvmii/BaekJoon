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
			// 사람이면
			for (int j = i - k; j <= i + k; j++) {
				// 양옆에의 거리에서 찾기
				if (j >= 0 && j < n && visited[j] != 1) {
					// 범위내에 있고 방문하지 않았다면
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