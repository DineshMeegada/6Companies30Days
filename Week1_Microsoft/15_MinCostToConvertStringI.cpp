#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> makeDistMat(vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    vector<vector<long long>> dist(26, vector<long long>(26, 1 << 29));
    for (int i = 0; i < 26; i++)
        dist[i][i] = 0;
    for (int i = 0; i < cost.size(); i++)
    {
        long long u = original[i] - 'a', v = changed[i] - 'a', wt = cost[i];
        dist[u][v] = min(dist[u][v], wt);
    }

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist;
}

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    int n = original.size();
    vector<vector<long long>> dist = makeDistMat(original, changed, cost);

    long long ans = 0, len = source.size();
    for (int i = 0; i < len; i++)
    {
        if (source[i] != target[i])
        {
            long long dis = dist[source[i] - 'a'][target[i] - 'a'];
            if (dis == 1 << 29)
                return -1;
            ans += dis;
        }
    }

    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string source, target;
    cin >> source >> target;
    int n;
    cin >> n;
    vector<char> original(n), changed(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> original[i] >> changed[i] >> cost[i];
    long long ans = minimumCost(source, target, original, changed, cost);
    cout << ans;

    return 0;
}