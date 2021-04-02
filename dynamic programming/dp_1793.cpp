#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n;
string dp[251];

string sum(string num1, string num2) {
    // 자리수가 큰 숫자들은 string으로 더하기

    long long sum = 0;
    string result;
    //1의 자리부터 더하기

    while (!num1.empty() || !num2.empty() || sum)
    {
        if (!num1.empty())
        {
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }

        result.push_back((sum % 10) + '0');
        // 10을 넘을경우 나머지만 남기기
        sum /= 10;
        // 10을 넘을경우 자리 올림
    }

    reverse(result.begin(), result.end());
    // 거꾸로 해주기
    return result;
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    dp[0] = '1';
    dp[1] = '1';
    dp[2] = '3';
    for (int i = 3; i < 251; i++) {
        dp[i] = sum(dp[i - 2], sum(dp[i - 2], dp[i - 1]));
        // 점화식 dp[i] = dp[i - 2] * 2 + dp[i - 1]
    }
    while (1) {
        cin >> n;
        if (cin.eof()) break;
        cout << dp[n] << '\n';
    }
}