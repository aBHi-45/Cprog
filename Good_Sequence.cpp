#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    unordered_map<long long, long long> freqMap;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        freqMap[val]++;
    }
    for (const auto entry : freqMap)
    {
        if (entry.first > entry.second)
        {
            ans += entry.second;
        }
        else
        {
            ans += (entry.second - entry.first);
        }
    }
    cout << ans;
    return 0;
}