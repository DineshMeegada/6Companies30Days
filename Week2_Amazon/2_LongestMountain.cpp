#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int> &arr)
{
    int ind = 1, n = arr.size();
    int ans = 0;
    while (ind < n - 1)
    {
        if (arr[ind] <= arr[ind - 1] || arr[ind] <= arr[ind + 1])
        {
            ind++;
            continue;
        }
        int left = ind - 1, right = ind + 1;
        while (left > 0 && arr[left] > arr[left - 1])
            left--;
        while (right < n - 1 && arr[right] > arr[right + 1])
            right++;
        ans = max(ans, right - left + 1);

        ind = right + 1;
    }

    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = longestMountain(arr);
    cout << ans;

    return 0;
}