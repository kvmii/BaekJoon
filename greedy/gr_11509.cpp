#include <iostream>

using namespace std;
int n, k;
int arr[1000001];
int visited[1000001];
int result = 0;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (arr[k + 1]) {
			// �տ� ���̰� 1������ �־��ٸ�
			arr[k + 1]--;
			arr[k]++;
			// ���� 1 ���߱�
		}
		else {
			// ���ٸ� k���� �߰�
			arr[k]++;
			result++;
		}
	}

	cout << result;

}