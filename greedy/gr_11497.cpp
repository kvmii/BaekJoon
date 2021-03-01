#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;

// 정규분포 처럼 만드는 것이 핵심
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			vec.push_back(a);
		}

		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		// 큰 순으로 정렬

		vector<int> a;
		vector<int> b;
		
		a.push_back(vec[0]);
		b.push_back(vec[0]);
		// 제일 큰 수를 둘다 push

		for (int i = 1; i < vec.size(); i += 2) {
			a.push_back(vec[i]);
			// 하나는 a 하나는 b에 push
			if (i == vec.size() - 1) break;
			b.push_back(vec[i + 1]);
		}

		int result = 0;

		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] - a[i + 1] > result) {
				result = a[i] - a[i + 1];
				// a부터 차가 제일 큰것 따지기
			}
		}

		for (int i = 0; i < b.size() - 1; i++) {
			if (b[i] - b[i + 1] > result) {
				result = b[i] - b[i + 1];
				// b도 a랑 마찬가지로
			}
		}

		cout << result << endl;
	}
}