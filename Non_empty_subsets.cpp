#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        int answer = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            answer = min(nums[i], answer);
        }
        cout << answer << "\n";
    }
    return 0;
}