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
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            long long val;
            cin >> val;
            answer = answer | val;
        }
        cout << answer << '\n';
    }
    return 0;
}