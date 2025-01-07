#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m){
    return row>=0 && row<n && col>=0 && col<m;
}

int average(vector<vector<int>>& img, int row, int col){
    int n = img.size(), m = img[0].size();
    long long total = 0, cnt = 0;
    for (int i=row-1; i<=row+1; i++){
        for (int j=col-1; j<=col+1; j++){
            if (isValid(i, j, n, m)) {
                total += img[i][j];
                cnt++;
            }
        }
    }

    return (int)(total/cnt);
}

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int n = img.size(), m = img[0].size();
    vector<vector<int>> ans(n, vector<int> (m, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ans[i][j] = average(img, i, j);
        }
    }

    return ans;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> img(n, vector<int> (m, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> img[i][j];
        }
    }

    vector<vector<int>> ans = imageSmoother(img);
    for (auto iter: ans){
        for (auto i: iter) cout << i << " " ;
        cout << endl;
    }
    
    return 0;
}