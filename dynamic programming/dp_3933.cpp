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
	// ���ڰ� 4�������� ���ι���ó�� Ǯ �� ������
	// ���Ʈ���� �̿�
	return 0;
}