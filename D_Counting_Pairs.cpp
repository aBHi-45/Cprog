#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int left, int right, long long sumL, long long sumR, long long sumNums, map<pair<int, int>, int> &Memo)
{
    if (left >= right)
    {
        Memo[make_pair(left, right)] = 0;
        return 0;
    }

    if (Memo.find(make_pair(left, right)) != Memo.end())
        return Memo[make_pair(left, right)];

    if (sumNums - (long long)(nums[left] + nums[right]) < sumL)
    {

        Memo[make_pair(left, right)] = solve(nums, left, right - 1, sumL, sumR, sumNums, Memo);
        return Memo[make_pair(left, right)];
    }
    else if (sumNums - (long long)(nums[left] + nums[right]) > sumR)
    {
        Memo[make_pair(left, right)] = solve(nums, left + 1, right, sumL, sumR, sumNums, Memo);
        return Memo[make_pair(left, right)];
    }
    else
    {

        Memo[make_pair(left, right)] = solve(nums, left, right - 1, sumL, sumR, sumNums, Memo) + solve(nums, left + 1, right, sumL, sumR, sumNums, Memo) + 1 - solve(nums, left + 1, right - 1, sumL, sumR, sumNums, Memo);
        return Memo[make_pair(left, right)];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long x, y;
        cin >> x;
        cin >> y;
        vector<int> nums(n, 0);
        long long sumNums = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            sumNums += nums[i];
        }

        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1;
        map<pair<int, int>, int> Memo;

        int count = solve(nums, i, j, x, y, sumNums, Memo);

        cout << count << "\n";
    }
    return 0;
}