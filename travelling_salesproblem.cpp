#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int tsp(int mask, int pos, int n, vector<vector<int>> &dist, vector<vector<int>> &dp)
{
    if (mask == (1 << n) - 1)
        return dist[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INF;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city, n, dist, dp);
            ans = min(ans, newCost);
        }
    }
    return dp[mask][pos] = ans;
}
int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    int result = tsp(1, 0, n, dist, dp);
    cout << "Minimum cost of the tour: " << result << endl;
    cout << "This program is executed by Sahil Singh (Roll No: 2400320100951)" << endl;
    return 0;
}