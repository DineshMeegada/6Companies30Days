#include <bits/stdc++.h>
using namespace std;

bool canTake(int n, vector<int> &off, vector<int> &needs)
{
    for (int i = 0; i < n; i++)
        if (needs[i] < off[i])
            return false;
    return true;
}

int findCost(int n, vector<int> &price, vector<int> &needs)
{
    int cost = 0;
    for (int i = 0; i < n; i++)
        cost += needs[i] * price[i];
    return cost;
}

void modifyNeeds(int n, vector<int> &needs, vector<int> &off, bool toAdd)
{
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int need = toAdd ? needs[i] + off[i] : needs[i] - off[i];
        needs[i] = need;
    }
}

int solve(int ind, int n, vector<int> &price, vector<vector<int>> &offers, vector<int> &needs)
{
    if (ind < 0)
    {
        int cost = findCost(n, price, needs);
        return cost;
    }

    int notTake = solve(ind - 1, n, price, offers, needs);
    int take = 1e9;
    if (canTake(n, offers[ind], needs))
    {
        modifyNeeds(n, needs, offers[ind], 0);
        take = offers[ind][n] + solve(ind, n, price, offers, needs);
        modifyNeeds(n, needs, offers[ind], 1);
    }

    return min(take, notTake);
}

int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
{
    int m = special.size();

    int ans = solve(m - 1, price.size(), price, special, needs);
    return ans;
}

int main()
{
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int m;
    cin >> m;
    vector<vector<int>> special(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> special[i][j];
    }
    vector<int> needs(n, 0);
    for (int i = 0; i < n; i++)
        cin >> needs[i];
    int ans = shoppingOffers(price, special, needs);
    cout << ans;

    return 0;
}