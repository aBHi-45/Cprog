#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long val;
        unordered_map<long long, long long> freqMap;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            if (val > 0)
                freqMap[val] += val;
        }

        long long ans = 0;
        priority_queue<long long> largeSums;

        for (const auto entry : freqMap)
        {
            largeSums.push(entry.second);
        }

        for (int i = 0; i < k && !largeSums.empty(); i++)
        {
            ans += largeSums.top();
            largeSums.pop();
        }

        cout << ans << "\n";
    }
    return 0;
}