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
        vector<int> IA(n);
        vector<int> IR(n);
        for (int i = 0; i < n; i++)
        {
            cin >> IA[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> IR[i];
        }
        vector<int> permut(n);
        set<int> added = {};
        int i = 0;
        for (i = 0; i < n; i++)
        {
            permut[i] = n - IA[i] - IR[n - 1 - i];
            if (added.count(permut[i]) == 1 || permut[i] <= 0)
            {
                cout << -1 << "\n";
                break;
            }
            else
                added.insert(permut[i]);
        }
        if (i < n)
            continue;
        for (int i = 0; i < n; i++)
        {
            cout << permut[i] << " ";
        }
        cout << "\n";
    }
}