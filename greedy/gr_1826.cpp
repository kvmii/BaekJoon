#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> vec;
int l, p;
int result = 0;

int main() {
	priority_queue<int> pq;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
	// �������ֱ�
	cin >> l >> p;

	int i = 0;
	while (1) {
		if (p >= l) break;
		// ���� ������

		while (i < vec.size() && p >= vec[i].first) {
			// ���� ����� �� �� �ִ� ������
			pq.push(vec[i].second);
			// �켱����ť�� �־��ֱ�
			i++;
		}

		if (pq.empty()) break;
		// �� ���ƺôٸ�

		p += pq.top();
		pq.pop();
		// �� �� �ִ� ���߿� ���Ḧ �� ���� ä��� ������ ä���
		result++;

	}

	if (l > p) cout << -1;
	// �������� ���ߴٸ�
	else cout << result;
}