#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    setIO("bcount");
    int N, Q;
    cin >> N >> Q;
    vector<int> Cows;
    for (int i = 0; i < N; i++)
    {
        int cowI;
        cin >> cowI;
        Cows.push_back(cowI);
    }
    vector<vector<int>> SumCows(4, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        SumCows[1][i + 1] = SumCows[1][i];
        SumCows[2][i + 1] = SumCows[2][i];
        SumCows[3][i + 1] = SumCows[3][i];
        SumCows[Cows[i]][i + 1]++;
    }
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << (SumCows[1][r] - SumCows[1][l - 1]) << " " << (SumCows[2][r] - SumCows[2][l - 1]) << " " << (SumCows[3][r] - SumCows[3][l - 1]) << endl;
    }
    return 0;
}