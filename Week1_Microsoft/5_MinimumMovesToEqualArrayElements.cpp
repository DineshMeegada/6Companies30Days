#include <bits/stdc++.h>
using namespace std;

int median(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int med = (n&1) ? arr[n/2] : (arr[n/2]+arr[n/2 - 1])/2;
    return med;
}

int minMoves2(vector<int>& nums) {
    int med = median(nums);

    int ans = 0;
    for (auto it: nums) ans += abs(it - med);
    return ans;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i=0; i<n; i++) cin >> nums[i];
    int ans = minMoves2(nums);
    cout << ans;

    return 0;
}