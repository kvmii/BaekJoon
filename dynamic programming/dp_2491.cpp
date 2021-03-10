#include <iostream>
#include <algorithm>

using namespace std;
int rdp[100001];
int ldp[100001];
int arr[100001];
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	rdp[1] = ldp[1] = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i + 1] >= arr[i]) {
			rdp[i + 1] = rdp[i] + 1;
		}
		else {
			rdp[i + 1] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		if (arr[i + 1] <= arr[i]) {
			ldp[i + 1] = ldp[i] + 1;
		}
		else {
			ldp[i + 1] = 1;
		}
	}

	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = max(result, max(rdp[i], ldp[i]));
	}
	cout << result;
}