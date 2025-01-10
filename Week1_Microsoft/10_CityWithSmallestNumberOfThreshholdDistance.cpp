#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm
int dijkstra(int source, int n, int k, vector<pair<int, int>> adj[])
{
    vector<int> dist(n, 1e9);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();

        if (dist[node] < d)
            continue;
        for (auto it : adj[node])
        {
            if (dist[it.first] <= d + it.second)
                continue;
            dist[it.first] = d + it.second;
            pq.push({dist[it.first], it.first});
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (i != source && dist[i] <= k)
            cnt++;
    return cnt;
}

int findTheCityDijkstra(int n, vector<vector<int>> &edges, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int city = -1, neigh = n;
    for (int i = 0; i < n; i++)
    {
        int cnt = dijkstra(i, n, k, adj);
        if (cnt <= neigh)
        {
            city = i;
            neigh = cnt;
        }
    }

    return city;
}

// Floyd Warshall Algorithm
int findTheCity(int n, vector<vector<int>> &edges, int k)
{
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        matrix[u][v] = wt;
        matrix[v][u] = wt;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == 1e9)
                    continue;
                matrix[i][j] = min(matrix[i][j],
                                   matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int city = -1, neigh = n;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] <= k)
                cnt++;
        }

        if (cnt <= neigh)
        {
            neigh = cnt;
            city = i;
        }
    }

    return city;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges(n - 1, vector<int>(3, 0));
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    int ans = findTheCity(n, edges, k);
    cout << ans;

    return 0;
}