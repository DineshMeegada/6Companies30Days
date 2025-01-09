#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int totalPts = 0;
    vector<int> points;
    vector<vector<int>> r;

    int bSearch(int num, vector<int> &points){
        int n = points.size();
        int low = 0, high = n-1;

        while (low <= high){
            int mid = low + (high - low)/2;

            if (points[mid] <= num) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }

public:
    Solution(vector<vector<int>>& rects) {
        int pts = 0;
        r = rects;
        for (auto p: rects){
            int cur = (p[2]-p[0]+1) * (p[3]-p[1]+1);
            totalPts += cur;
            points.push_back(totalPts);
        }
    }
    
    vector<int> pick() {
        int num = rand() % totalPts;
        int ind = bSearch(num, points);

        vector<int> rec = r[ind];
        int x = rec[0] + rand() % (rec[2]-rec[0]+1);
        int y = rec[1] + rand() % (rec[3]-rec[1]+1);

        return {x,y};
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> rects(n, vector<int> (4, 0));
    for (int i=0; i<n; i++) cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];
    Solution* obj = new Solution(rects);
    vector<int> param_1 = obj->pick();
    for (auto i: param_1) cout << i << " ";
    cout << endl;
    

    return 0;
}