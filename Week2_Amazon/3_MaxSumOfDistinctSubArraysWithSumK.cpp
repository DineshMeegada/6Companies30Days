#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    long long sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        mp[nums[i]]++;
        sum += nums[i];
    }
    if (mp.size() == k)
        ans = max(ans, sum);

    for (int right = k; right < n; right++)
    {
        int left = right - k;
        mp[nums[left]]--;
        mp[nums[right]]++;
        sum += nums[right] - nums[left];
        if (mp[nums[left]] == 0)
            mp.erase(nums[left]);

        if (mp.size() == k)
            ans = max(ans, sum);
    }

    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maximumSubarraySum(nums, k);

    return 0;
}