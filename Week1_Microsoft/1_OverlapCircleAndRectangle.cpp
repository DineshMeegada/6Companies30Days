#include <bits/stdc++.h>
using namespace std;

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    int xn = max(x1, min(xCenter, x2));
    int yn = max(y1, min(yCenter, y2));

    int dx = xn - xCenter;
    int dy = yn - yCenter;

    return dx*dx + dy*dy <= radius*radius;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int radius, xCenter, yCenter, x1, y1, x2, y2;
    cin >> radius >> xCenter >> yCenter >> x1 >> y1 >> x2 >> y2;

    bool ans = checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);
    cout << (ans ? "true" : "false");


    return 0;
}