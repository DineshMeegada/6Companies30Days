#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    vector<int> arr(nums.begin(), nums.end());
    sort(arr.begin(), arr.end());

    int n = nums.size(), ind = n - 1;
    for (int i = 1; i < n; i += 2)
        nums[i] = arr[ind--];
    for (int i = 0; i < n; i += 2)
        nums[i] = arr[ind--];
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
    wiggleSort(nums);
    for (auto i : nums)
        cout << i << " ";

    return 0;
}