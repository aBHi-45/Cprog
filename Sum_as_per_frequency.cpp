#include <bits/stdc++.h>
using namespace std;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<long long, long long> freq;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    vector<long long> sumFreq(n + 1, 0);

    for (auto i : freq)
    {
        sumFreq[i.second] += i.second * i.first;
    }

    vector<long long> sumInt(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        sumInt[i] = sumInt[i - 1] + sumFreq[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sumInt[r] - sumInt[l - 1] << "\n";
    }

    return 0;
}