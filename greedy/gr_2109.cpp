#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> vec;
int visited[10001];
int result = 0;

// 13904������ ���
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a, b });
		// ����, ��
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	// ���� ���� ������ ����

	for (int i = 0; i < vec.size(); i++) {
		int score = vec[i].first;
		int cnt = vec[i].second;
		while (cnt >= 1) {
			if (visited[cnt] == 0) {
				// �ش����� ����ִٸ�
				visited[cnt] = score;
				result += score;
				break;
			}
			// �ٸ� ���� ������ �Ϸ� ���� ����
			cnt--;
		}
	}

	cout << result;

}