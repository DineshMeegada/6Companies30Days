#include <bits/stdc++.h>
using namespace std;

int Atmost(vector<int> &arr, int k)
{
    int n = arr.size();
    int ans = 0, cnt = 0;
    int left = 0, right = 0;

    while (right < n && left <= right)
    {
        cnt += arr[right] & 1;
        while (cnt > k)
        {
            cnt -= arr[left] & 1;
            left++;
        }

        ans += right - left + 1;
        right++;
    }

    return ans;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return Atmost(nums, k) - Atmost(nums, k - 1);
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

    int ans = numberOfSubarrays(nums, k);
    cout << ans;

    return 0;
}