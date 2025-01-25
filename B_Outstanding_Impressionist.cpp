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
        vector<int> count(2 * n + 1, 0);
        vector<int> sum(2 * n + 1, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> left[i];
            cin >> right[i];
            if (left[i] == right[i])
            {
                count[left[i]]++;
                sum[left[i]] = 1;
            }
        }

        for (int i = 2; i <= 2 * n; i++)
            sum[i] += sum[i - 1];

        for (int i = 0; i < n; i++)
        {
            cout << ((left[i] == right[i] ? count[left[i]] <= 1 : sum[right[i]] - sum[left[i] - 1] < right[i] - left[i] + 1) ? 1
                                                                                                                             : 0);
                }
        cout << '\n';
    }
    return 0;
}