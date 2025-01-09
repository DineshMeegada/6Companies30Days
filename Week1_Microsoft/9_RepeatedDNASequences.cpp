#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    int n = s.size();
    vector<string> ans;
    if (n < 10)
        return ans;

    unordered_map<string, int> mp;
    string cur = "";
    for (int i = 0; i < 10; i++)
        cur += s[i];
    mp[cur]++;

    for (int i = 10; i < n; i++)
    {
        cur.erase(0, 1);
        cur += s[i];
        mp[cur]++;
    }

    for (auto it : mp)
    {
        if (it.second > 1)
            ans.push_back(it.first);
    }

    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;
    vector<string> ans = findRepeatedDnaSequences(s);
    for (auto it : ans)
        cout << it << endl;

    return 0;
}