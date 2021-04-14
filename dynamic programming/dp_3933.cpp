#include <iostream>
#include <cmath>

using namespace std;
int n;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0)break;
		int num = sqrt(n);
		int cnt = 0;
		for (int i = 1; i <= num; i++) {
			if (i * i == n) {
				cnt++;
				break;
			}
			for (int j = i; j <= num; j++) {
				if (j * j + i * i == n) {
					cnt++;
					break;
				}
				else if (j * j + i * i > n) break;
				for (int k = j; k <= num; k++) {
					if (j * j + i * i + k * k == n) {
						cnt++;
						break;
					}
					else if (j * j + i * i + k * k > n) break;
					for (int l = k; l <= num; l++) {
						if (j * j + i * i + k * k + l * l == n) {
							cnt++;
							break;
						}
						else if (j * j + i * i + k * k + l * l > n) break;
					}
				
				}
			}
		}
		cout << cnt << '\n';
	}
	// 숫자가 4개까지라서 코인문제처럼 풀 수 없었다
	// 브루트포스 이용
	return 0;
}