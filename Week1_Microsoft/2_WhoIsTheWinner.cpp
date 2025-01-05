#include <bits/stdc++.h>
using namespace std;

int findTheWinner(int n, int k) {
    queue<int> q;
    for (int i=1; i<=n; i++) q.push(i);

    while (q.size() > 1){
        for (int i=1; i<k; i++){
            int cur = q.front();
            q.pop();
            q.push(cur);
        }

        q.pop();
    }
    return q.front();
}


int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    int ans = findTheWinner(n, k);
    cout << ans;

    return 0;
}