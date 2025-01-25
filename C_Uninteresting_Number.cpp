#include <bits/stdc++.h>
using namespace std;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long sumDigits = 0;
        unordered_map<int, long long> count;
        string number;
        cin >> number;
        for (int i = 0; i < number.length(); i++)
        {
            sumDigits += (long long)number[i] - '0';
            if (number[i] - '0' == 2 || number[i] - '0' == 3)
            {
                count[number[i] - '0']++;
            }
        }

        if (sumDigits % 9 == 0)
        {
            cout << "YES\n";
            continue;
        }

        bool isFound = false;

        for (int i = 0; i <= count[2]; i++)
        {
            for (int j = 0; j <= count[3]; j++)
            {
                if ((sumDigits + 2 * i + 6 * j) % 9 == 0)
                {
                    cout << "YES\n";
                    isFound = true;
                    break;
                }
            }
            if (isFound)
                break;
        }

        if (!isFound)
            cout << "NO\n";
    }
    return 0;
}