#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        cin >> k;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long val;
            cin >> val;
            sum += val;
        }

        long long ans = sum - (k + 1) * n < 0 ? 0 : (sum - (k + 1) * n) / (k + 1) + 1;

        cout << ans << "\n";
    }
    return 0;
}