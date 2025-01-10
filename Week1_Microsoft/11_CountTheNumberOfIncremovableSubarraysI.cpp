#include <bits/stdc++.h>
using namespace std;

int incremovableSubarrayCount(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prev = -1, isInc = 1;
            for (int k = 0; k < n; k++)
            {
                if (k >= i && k <= j)
                    continue;
                if (prev != -1 && nums[k] <= prev)
                {
                    isInc = 0;
                    break;
                }
                prev = nums[k];
            }
            if (isInc)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = incremovableSubarrayCount(nums);
    cout << ans;

    return 0;
}