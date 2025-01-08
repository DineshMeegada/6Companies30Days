#include <bits/stdc++.h>
using namespace std;

int binary_search(int target, vector<int> &arr){
    int n = arr.size();
    if (n == 0) return 0;
    int low = 0, high = n-1;

    while (low <= high){
        int mid = low + (high - low)/2;

        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

bool comparator(vector<int> &a, vector<int> &b){
    if (a[0] == b[0]) return a[1] > b[1];
    return (a[0] < b[0]);
}

int maxEnvelopes(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end(), comparator);
    int n = arr.size();
    vector<int> ans;

    for (int i=0; i<n; i++){
        int ind = binary_search(arr[i][1], ans);
        if (ind == ans.size()) ans.push_back(arr[i][1]);
        else if (ans[ind] >= arr[i][1]) ans[ind] = arr[i][1];
    }
    return ans.size();
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (2, 0));
    for (int i=0; i<n; i++) cin >> arr[i][0] >> arr[i][1];
    int ans = maxEnvelopes(arr);
    cout << ans;

    return 0;
}