#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    unordered_map<char, int> mp1, mp2;
    int n = secret.size();

    int bulls = 0, cows = 0;
    for (int i=0; i<n; i++){
        if (secret[i] == guess[i]) bulls++;
        else {
            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }
    }

    for (auto it: mp1){
        if (mp2.count(it.first)) 
            cows += min(it.second, mp2[it.first]);
    }

    string ans = to_string(bulls) + "A" + to_string(cows) + "B";
    return ans;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string secret, guess;
    cin >> secret >> guess;
    string ans = getHint(secret, guess);
    cout << ans;
    
    return 0;
}