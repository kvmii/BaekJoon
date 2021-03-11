#include<iostream>
#include<string>
#include<vector>
using namespace std;
int check(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] == s[s.size() - i - 1])
        {
            continue;
        }
        else
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int num;
    cin >> num;
    string s;
    for (int i = 0; i < num; i++)
    {
        cin >> s;
        int num = check(s);
        if (num != -1)
        {
            string a = s.substr(num, s.size() - 1 - 2 * num);
            string b = s.substr(num + 1, s.size() - 1 - 2 * num);
 
            if (check(a) == -1 || check(b) == -1)
            {
                cout << "1" << endl;
            }
            else {
                cout << "2" << endl;
            }
        }
        else
        {
            cout << "0" << endl;
        }


    }
}