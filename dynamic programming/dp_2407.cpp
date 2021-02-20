#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100 + 1;

int n, m;

string dp[MAX][MAX];

string sum(string num1, string num2){

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

        if (!num2.empty()){
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

//nCr = n-1Cr + n-1Cr-1

string comb(int n, int r){
    if (n == r || r == 0)
        return "1";
    
    string& result = dp[n][r];
    if (result != "")
        return result;
    result = sum(comb(n - 1, r - 1), comb(n - 1, r));

    return result;
}

int main(){
    cin >> n >> m;

    cout << comb(n, m) << endl;

    return 0;
    // long long으로도 한계가 있어서 string으로 변환
    // 쉬운문제인줄 알았는데 엄청 오래걸렸다
}
