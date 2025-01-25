#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<long long>> Menus(n, vector<long long>(m, 0));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> Menus[i][j];
        }
    }
    vector<long long> goodPrices(m, 0);

    for (long long i = 0; i < m; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            goodPrices[i] = max(goodPrices[i], Menus[j][i]);
        }
    }

    vector<long long> goodPricesCount(n, 0);
    vector<long long> sumPrices(n, 0);
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            if (goodPrices[j] == Menus[i][j])
            {
                goodPricesCount[i]++;
            }
            sumPrices[i] += (long long)Menus[i][j];
        }
    }

    long long answer = 1;
    long long maxCount = 1;
    long long maxSum = 1;
    for (int i = 0; i < n; i++)
    {
        if (goodPricesCount[i] > maxCount)
        {
            answer = i + 1;
            maxCount = goodPricesCount[i];
            maxSum = sumPrices[i];
        }
        else if (goodPricesCount[i] == maxCount && sumPrices[i] > maxSum)
        {
            answer = i + 1;
            maxSum = sumPrices[i];
        }
    }
    cout << answer;
    return 0;
}
