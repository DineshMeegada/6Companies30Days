#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string st)
{
    int n = st.size();
    if (n == 0)
        return false;
    for (int i = 0; i < n / 2; i++)
    {
        if (st[i] != st[n - i - 1])
            return false;
    }

    return true;
}

int maxProduct(string s)
{
    int n = s.size();
    unordered_map<int, int> pali;
    for (int mask = 1; mask < 1 << n; mask++)
    {
        string cur = "";
        for (int i = 0; i < n; i++)
        {
            int num = 1 << i;
            if (mask & num)
                cur += s[i];
        }

        if (isPalindrome(cur))
            pali[mask] = cur.size();
    }

    int ans = 0;
    for (auto it1 : pali)
    {
        for (auto it2 : pali)
        {
            if ((it1.first & it2.first) == 0)
                ans = max(ans, it1.second * it2.second);
        }
    }

    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;
    int ans = maxProduct(s);
    cout << ans;

    return 0;
}