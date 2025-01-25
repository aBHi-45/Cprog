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
        int n;
        cin >> n;
        vector<long long> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<long long> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans[i] = nums[i];
            }
            else
            {
                ans[i] = ans[i - 1] % nums[i] == 0 ? ans[i - 1] : ans[i - 1] + nums[i] - ans[i - 1] % nums[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}